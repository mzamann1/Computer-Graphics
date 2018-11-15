#include "Color.h"
#include "Point2d.h"
#include "glut.h"


class Pen
{
private:
	Point2d curr_point; 
	Color color;
	bool penState;

public:
	Pen()
	{
		penState = true;
	}
	Pen(int x,int y)
	{
		curr_point.setPoint(x, y);
	}
	Pen(int x, int y, float R, float G, float B)
	{
		curr_point.setPoint(x, y);
		color.Set_Color(R, G, B);
	}
	void moveTo(Point2d point)
	{
		curr_point.setPoint(point.getX(),point.getY());
	}
	void moveTo(int x, int y)
	{
		curr_point.setPoint(x, y);
	}
	void lineTo(Point2d point)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2d(curr_point.getX(), curr_point.getY());
		glVertex2d(point.getX(), point.getY());
		glEnd();
		glFlush();
		curr_point.setPoint(point.getX(),point.getY());
	}
	void lineTo(int x, int y)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2d(curr_point.getX(), curr_point.getY());
		glVertex2d(x, y);
		glEnd();
		glFlush();
		curr_point.setPoint(x, y);
	}
	void lineRel(int x, int y)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2d(curr_point.getX(), curr_point.getY());
		glVertex2d(curr_point.getX()+x, curr_point.getY()+y);
		glEnd();
		glFlush();

		curr_point.setPoint(curr_point.getX() + x, curr_point.getY() + y);
	}
	void moveRel(int x,int y)
	{
		curr_point.setPoint(curr_point.getX() + x, curr_point.getY() + y);
	}


};