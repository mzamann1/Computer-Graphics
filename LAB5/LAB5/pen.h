#include <stdio.h>
#include "point2d.h"
#include "color.h"
#ifndef PEN_H
#define PEN_H
class pen
{
private:
    point2d cp;
    bool penState;
    color c;
public:
    pen()
    {
        penState = true;
    }
    pen(int x, int y)
    {
        cp.setPoint(x,y);
        
    }
    pen(int x, int y, float r, float g, float b)
    {
        cp.setPoint(x,y);
        c.setColor(r,g,b);
        glColor3f(c.getR(),c.getG(),c.getB());
    }
    void moveTo(point2d cp)
    {
        cp.setPoint(cp.getX(),cp.getY());
    }
    void lineTo(point2d pt )
    {
        glBegin(GL_LINE_STRIP);
        glVertex2d(cp.getX(),cp.getY());
        glVertex2d(pt.getX(),pt.getY());
        glEnd();
        glFlush();
        cp.setPoint(pt.getX(),pt.getY());
    }
    void moveTo(int x, int y)
    {
        cp.setPoint(x,y);
    }
    void lineTo(int x, int y)
    {
        glBegin(GL_LINE_STRIP);
        glVertex2d(cp.getX(),cp.getY());
        glVertex2d(x,y);
        glEnd();
        glFlush();
        cp.setPoint(x,y);   
    }
    void moveRel(int x,int y)
    {
        cp.setPoint(cp.getX()+x,cp.getY()+y);
    }
    void lineRel(int x, int y)
    {
        glBegin(GL_LINE_STRIP);
        glVertex2d(cp.getX(),cp.getY());
        glVertex2d(cp.getX()+x,cp.getY()+y);
        glEnd();
        glFlush();
        cp.setPoint(cp.getX()+x,cp.getY()+y);    
    }

};
#endif /* PEN_H */


