#include <GL/glut.h>
#include <iostream>
#include <fstream> 
#include <string> 
#include<math.h>
#include "pen.h"

 pen myPen;

void display()
{
    myPen.moveTo(1,1);
    myPen.lineTo(5,5);
}



int SWidth = 640;
int SHeight = 480;
const float DEG2RAD = 3.14159/180; 
// Function Prototypes
void initialiseWindow(void);
void registerCalbacks(void);
void initGL(void);
void displayFunc(void);
void drawCircle(float radius, int sx, int sy);
void mouseFunc(int button, int state, int x, int y);
void drawToolbar();

using namespace std;

int main (int argc,char *argv[])
{	
	glutInit(&argc,argv);
	initialiseWindow();
	registerCalbacks();
	initGL();
	glutMainLoop();
}
void initialiseWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(SWidth,SHeight);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Lab-01: Task 1");
}

void registerCalbacks(void)
{
	glutDisplayFunc(displayFunc);
	glutMouseFunc(mouseFunc);

}  
bool clickFlag = false;
int prevX=-1, prevY=-1;
string penType = "";
void mouseFunc(int button, int state, int x, int y)
{
    
	if(button==2)
	{
		prevX=-1;
		prevY=-1;
		return;
	}

	
	
	//glVertex2i(10,10);	 //glVertex2i(20,10);	 //glVertex2i(20,20);	 //glVertex2i(10,20);	
	if( (x>=10 && x<=20) && (y>=10 && y<=20) )
	{
		penType = "circle";
		return;
	}
	//glVertex2i(30,10);	 //glVertex2i(40,10);	 //glVertex2i(40,20);	 //glVertex2i(30,20);	
	else if( (x>=30 && x<=40) && (y>=10 && y<=20) )
	{
		penType = "freehand";
		prevX=-1;
		prevY=-1;

		return;
	} 
	else
	{	
		//return;
	}


	if(state == 0)
	{
		if( penType == "freehand")
		{	
					
			glColor3ub(0,0,0);
			if(prevX < 0 && prevY < 0)
			{
				clickFlag = true;
				glBegin(GL_LINE_STRIP);      		
				glVertex2d( x, y ); 
				glVertex2d( x, y );  		
				glEnd();				
			}
			else
			{
				glBegin(GL_LINE_STRIP);      		
				glVertex2d( prevX, prevY );  		
				glVertex2d( x, y);  		
				glEnd();		
			}
		}
		
		else if( penType == "circle")
		{
			glColor3ub(255,255,255);
			drawCircle(20,x,y);
		}
	}
	
	prevX = x;
	prevY = y;

	glFlush();	
	  
}


void displayFunc()
{
	glClearColor(0,255,0,1.0);			
	//gl ClearColor(R,G,B,Trasparency(a)) ONLY SETS BACKGROUND COLOR
	glLineWidth(2.0);
	glClear(GL_COLOR_BUFFER_BIT);
	// APPLY THE SELECTED COLOR SCHEME FOR BACKGROUND OF WINDOW
	glColor3f(1,1,1);	// SETS FOREGROUND COLOR
	glPointSize(4.0);
	//drawToolbar();
        display();
	glFlush();
}
void initGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,10,0,10);
}


void drawCircle(float radius, int sx, int sy)
{
   const float DEG2RAD = 3.14159/180; 
   glBegin(GL_LINE_LOOP); 
   for (int i=0; i < 360; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(sx+cos(degInRad)*radius,sy+sin(degInRad)*radius);
   } 
   glEnd();
}

void drawToolbar()
{
	glBegin(GL_POLYGON);			
	glColor3ub(255,255,255);	
	glVertex2i(10,10);	
	glVertex2i(20,10);	
	glVertex2i(20,20);	
	glVertex2i(10,20);	
	glEnd();
	
	glBegin(GL_POLYGON);			
	glColor3ub(0,0,0);	
	glVertex2i(30,10);
	glVertex2i(40,10);
	glVertex2i(40,20);	 
	glVertex2i(30,20);	
	glEnd();

	glFlush();
}
