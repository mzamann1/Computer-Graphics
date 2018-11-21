


#include <windows.h>  // For MS Windows
#include <glut.h> // GLUT, includes glu.h and gl.h
#include <math.h>
#include "point2d.h"
#include "iostream"

#define PI 3.148

using namespace std;

int SWidth = 640;
int SHeight = 480;
int value;
Point2d myVList[36];

void initialiseWindow(void);
void registerCallBacks(void);
void initGL(void);
void makeNGon(float, int, Point2d);
void displayFunc(void);

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted.
*/

int main(int argc, char** argv) {

	cout << "Please Enter Number of Corners : \t";
	cin >> value;
	glutInit(&argc, argv);                 // Initialize GLUT
	initialiseWindow();
	registerCallBacks();
	initGL();
	glutMainLoop();
	return 0;
}

void initialiseWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SWidth, SHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Making N-Gon");
}

void registerCallBacks(void)
{
	glutDisplayFunc(displayFunc);
}

void initGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, SWidth, 0.0, SHeight);
	glViewport(0, 0, 640, 480);
}

void makeNGon(float R, int n, Point2d c)
{
	if (n < 3)
		return;

	float angle = 0.0f;
	float incAngle = (2 * PI) / n;

	glBegin(GL_LINE_STRIP);

	for (int i = 0; i <= n; i++)
	{
		myVList[i].setPoint(c.getX() + (R*cos(angle)), c.getY() + (R*sin(angle)));
		myVList[i].Draw();
		angle += incAngle;
	}

	glEnd();
}

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_LINE_SMOOTH); //for smooth edges
	glLineWidth(2.0); //used for sharpness of edges
	glColor3f(1.0f, 1.0f, 1.0f);
	makeNGon(100, value, Point2d(300, 250)); /*center value is the no. of points to make any Ngon
										 3 for triangle, 4 for square, 5 for pentagon, 6 hexagon,
										 7 for heptagon, 8 for octagon, 9 for nanogon, 10 for decagon.*/
	glFlush();
}

