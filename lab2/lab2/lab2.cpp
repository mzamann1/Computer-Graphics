// lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "glut.h"
#include "iostream"
#include "fstream"


using namespace std;

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //background color
	glColor3f(0.0f, 0.0f,0.0f); //drawing color
	//glPointSize(9.0);
	glLineWidth(2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0); //gluOrtho2D() routine sets the transformation we need for a screen window that is 640 pixels wide by 480 pixels high.
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*glBegin(GL_POINTS);
	glVertex2i(100, 50);
	glVertex2i(100, 130);
	glVertex2i(150, 130);
	glEnd();
	*/
	glBegin(GL_LINE_LOOP);
	glVertex2i(10, 10);
	glVertex2i(40, 10);
	glVertex2i(40, 30);
	glVertex2i(25, 40);
	glVertex2i(10, 30);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(15, 10);
	glVertex2i(15, 20);
	glVertex2i(20, 20);
	glVertex2i(20, 10);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(13, 33);
	glVertex2i(13, 40);
	glVertex2i(18, 40);
	glVertex2i(18, 36);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(25, 30);
	glVertex2i(35, 30);
	glVertex2i(35, 25);
	glVertex2i(25, 25);
	glEnd();


	glFlush(); //send output to the screen
}



int main(int argc,char** argv)
{

/*glutDisplayFunc(myDisplay); Whenever the system determines that a screen window should be
redrawn it issues a “redraw” event. This happens when the window is first opened, and when the window is
exposed by moving another window off of it. Here the function myDisplay() is registered as the callback
function for a redraw event.


• glutReshapeFunc(myReshape); Screen windows can be reshaped by the user, usually by dragging a
corner of the window to a new position with the mouse. (Simply moving the window does not produce a
reshape event.) Here the function myReshape() is registered with the “reshape” event. As we shall see,
myReshape() is automatically passed arguments that report the new width and height of the reshaped
window.


• glutMouseFunc(myMouse); When one of the mouse buttons is pressed or released a mouse event is
issued. Here myMouse() is registered as the function to be called when a mouse event occurs. myMouse() is
automatically passed arguments that describe the mouse location and the nature of the button action.


• glutKeyboardFunc(myKeyboard); This registers the function myKeyboard() with the event of
pressing or releasing some key on the keyboard. myKeyboard() is automatically passed arguments that tell
which key was pressed. Conveniently, it is also passed data as to the location of the mouse at the time the
key was pressed.

If a particular program does not use mouse interaction, the corresponding callback function need not be
registered or written. Then mouse clicks have no effect in the program. The same is true for programs that have
no keyboard interaction.


The final function shown in Figure 2.2 is glutMainLoop(). When this is executed the program draws the
initial picture and enters an unending loop, in which it simply waits for events to occur. (A program is normally
terminated by clicking in the “go away” box that is attached to each window.)*/





/* glutInit(&argc, argv); This function initializes the toolkit. Its arguments are the standard ones
for passing command line information; we will make no use of them here.


• glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); This function specifies how the display
should be initialized. The built-in constants GLUT_SINGLE and GLUT_RGB, which are OR’d together,
indicate that a single display buffer should be allocated and that colors are specified using desired
amounts of red, green, and blue. (Later we will alter these arguments: for example, we will use double
buffering for smooth animation.)


• glutInitWindowSize(640,480); This function specifies that the screen window should initially
be 640 pixels wide by 480 pixels high. When the program is running the user can resize this window as
desired.


• glutInitWindowPosition(100, 150); This function specifies that the window’s upper left
corner should be positioned on the screen 100 pixels from the left edge and 150 pixels down from the top.
When the program is running the user can move this window wherever desired.


• glutCreateWindow("my first attempt"); This function actually opens and displays the
screen window, putting the title “my first attempt” in the title bar.*/


	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(300, 300); // set window size
	glutInitWindowPosition(0, 0); // set window position on screen
	glutCreateWindow("Home");
	glutDisplayFunc(myDisplay);
	myInit();    // additional initializations as necessary
	glutMainLoop();

	return 0;
}

