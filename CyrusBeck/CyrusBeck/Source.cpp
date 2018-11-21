
#include <vector>
#include "Ngon.h"
#include "Ball.h"
#include "glut.h"
// Constraint: Initially, ball should lie inside some polygon.
// The smaller the radius of the ball, the more accurate will the results be.

using namespace std;

int screenWidth = 720;
int screenHeight = 540;

vector<Ngon> polygons;
Ball ball(1.3, 0, Ray2({ 0, 0 }, { 26, 26 }));

void myInit()
{
	glClearColor(0.9, 1.0, 0.6, 1.0);
	glLineWidth(2.6);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -75.0, 75.0);

	//polygons.push_back({ { 0, 0 }, 7, 70, 90 });		// the heptagon
	polygons.push_back({ { 25, 25 }, 3, 17, 225 });		// the triangle
	polygons.push_back({ { 0, 0 }, 4, 80, 315 });	// the square
	polygons.push_back({ { -25, -25 }, 5, 17, 45 });	// the pentagon
	polygons.push_back({ { 25, -25 }, 6, 17, 135 });	// the hexagon
	//polygons.push_back( {{0,0}, 8, 67.5, 67.5 });
	//polygons.push_back({ { 0, 0 }, 8, 80, 67.5 });// the octagon
}

/* defines the candidate interval from 0 to infinity */
void resetCandidateInterval(double& tIn, double& tOut)
{
	tIn = 0;
	tOut = numeric_limits<double>::infinity();
}

/* if the line segment(side of a polygon) intersects the ray (i.e. the ball's movingPath), chops the candidate interval,
returns false if ray entirely misses the polygon */
bool cyrusBeckClip(double& tIn, double& tOut, double numer, double denom)
{
	double tHit = numer / denom;

	if (denom < 0)
	{
		if (tHit > tOut) return false;
		else if (tHit > tIn) tIn = tHit;
	}
	else if (denom > 0)
	{
		if (tHit < tIn) return false;
		else if (tHit < tOut) tOut = tHit;
	}
	else if (numer <= 0)
		return false;

	return true;
}

/* determines the side of the polygon which ray is going to hit first (or the earliest), calculates tHit,
B (starting point of that side of polygon), n (normal to that side) and whether to reflect inside or outside */
double computeEarliestHit(Point2 A, Point2& B, Vector2& n, bool& reflectInside)
{
	double tIn, tOut;
	double tHit = numeric_limits<double>::infinity();
	bool rayHitsPolygon;

	for (size_t i = 0; i < polygons.size(); i++)
	{
		Ngon ithPolygon = polygons.at(i);
		resetCandidateInterval(tIn, tOut);
		rayHitsPolygon = true;

		double prev_tIn, prev_tOut;

		Point2 tempB;
		Vector2 tempN;
		//printf("\nA = (%.3f, %.3f)", ball.getBase().getX(), ball.getBase().getY());
		//printf("\nPolygon # %d", (i + 1));

		for (int j = 0; j < ithPolygon.sides(); j++)
		{
			// determine normal
			Vector2 normal = ithPolygon.getVertex((j + 1) % ithPolygon.sides()) - ithPolygon.getVertex(j);
			normal.set(normal.deltaY(), -normal.deltaX());

			// calculate numerator and denominator
			double numer = dot(normal, ithPolygon.getVertex(j) - A);
			double denom = dot(normal, ball.getDir());

			// to determine if the candidate interval changes during this iteration
			prev_tIn = tIn;
			prev_tOut = tOut;

			if (!cyrusBeckClip(tIn, tOut, numer, denom))
			{
				rayHitsPolygon = false;
				break;
			}

			if (prev_tIn < tIn || prev_tOut > tOut && tIn == 0) // candidate interval changes during this iteration
			{
				// store Point B and the normal vector
				tempB = Point2(ithPolygon.getVertex(j).getX(), ithPolygon.getVertex(j).getY());
				tempN = normal;
			}

			//printf("\nnumer = %.3f, denom = %.3f", numer, denom);
			//printf("\ntIn = %.3f\ttOut = %.3f", tIn, tOut);
		}

		if (rayHitsPolygon)
		{
			if (tIn > 0 && tIn < tHit) // ball lies outside the hitting polygon
			{
				tHit = tIn;
				reflectInside = false;

				B = tempB;
				n = tempN;
			}
			else if (tOut < tHit) // ball lies inside the hitting polygon
			{
				tHit = tOut;
				reflectInside = true;

				B = tempB;
				n = tempN;
			}
		}
	}

	return tHit;
}

void refreshWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.5, 0.6);
	for (size_t i = 0; i < polygons.size(); i++)
		polygons.at(i).draw();

	glColor3f(0.7, 0, 0);
	ball.drawBall();
}

void myDisplay(void)
{
	refreshWindow();
	glutSwapBuffers();
}

void myTimer(int)
{
	static Point2 B;
	static Vector2 n;
	static bool reflectInside;
	static double tHit = computeEarliestHit(ball.getBase(), B, n, reflectInside); // first time initialization of tHit, B, n, reflectInside

	if (tHit < 0.05) // reflect, compute the earliest hit (i.e. get tHit, B, n and reflectInside)
	{
		if (reflectInside)
			n = -1 * n;

		Vector2 newDirection = reflect(ball.getDir(), n);

		//printf("\na = (%.3f, %.3f), n = (%.3f, %.3f), r = (%.3f, %.3f), B = (%.3f, %.3f)", ball.getDir().deltaX(), ball.getDir().deltaY(), n.deltaX(), n.deltaY(), newDirection.deltaX(), newDirection.deltaY(), B.getX(), B.getY());

		ball.setMovingPath(ball.getBase(), newDirection);
		tHit = computeEarliestHit(ball.getBase(), B, n, reflectInside);
	}

	// move the ball, utilize B and n computed previously to calculate the new tHit, do this until tHit < 0.05
	ball.moveBall();

	double numer = dot(n, B - ball.getBase());
	double denom = dot(n, ball.getDir());

	tHit = numer / denom;

	//printf("\nearliest_tHit = %.5f", tHit);

	glutPostRedisplay();
	glutTimerFunc(1000 / 60, myTimer, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(150, 100);
	glutCreateWindow("Reflections In A Chamber");

	glutDisplayFunc(myDisplay);
	glutTimerFunc(0, myTimer, 0);
	myInit();

	glutMainLoop();
}