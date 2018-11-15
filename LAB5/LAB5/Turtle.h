/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Turtle.h
 * Author: panther
 *
 * Created on October 20, 2018, 11:31 PM
 */

#include <string>
#include <string.h>
#include "point2d.h"
using namespace std;


#ifndef TURTLE_H
#define TURTLE_H



#endif /* TURTLE_H */

class Turtle
{
private:
    point2d cp;
    float cd;
public:
    Turtle()
    {
        cp= point2d(0,0),cd = 0;
    }
    Turtle(point2d pt, float d)
    {
        cp = pt;
        cd = d;
    }
   void moveTo(int x, int y)
    {
        cp.setPoint(x,y);
    }
    void lineTo(int x, int y )
    {
        glBegin(GL_LINE_STRIP);
        glVertex2d(cp.getX(),cp.getY());
        glVertex2d(x,y);
        glEnd();
        glFlush();
        cp.setPoint(x,y);
    }
    void turnTo(float d)
    {
        cd = d;
        
    }
    void turn(float d)
    {
        cd = cd + d;
        
    }
    void forward(float d, int f)
    {
        float x = cp.getX() + d * cos(0.017453393 * cd);
        float y = cp.getY() + d * sin(0.017453393 * cd);
        if(f == 1)
            lineTo(x,y);
        else
            moveTo(x,y);
    }
    void drawPath(string s)
    {
        int i = 0;
        for(i = 0; i< s.length(); i++)
        {
            string subS = s.substr(i,1);
            if(subS == "F")
            {
                forward(10,1);
                        
            }else if(subS == "-")
            {
                turn(-(59.99));
            }else if( subS == "+")
            {
                turn(59.99);
            }
        }
    }
    
};
