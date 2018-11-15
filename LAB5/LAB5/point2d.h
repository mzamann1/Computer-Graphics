/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <math.h>
#include <glut.h>

/* 
 * File:   point2d.h
 * Author: panther
 *
 * Created on October 9, 2018, 10:16 PM
 */

#ifndef NGON_H
#define NGON_H
class point2d{
private:
    float x;
    float y;

public:  
    point2d()
    { 
        x = 0;
        y = 0;
    }
    point2d(int xin, int yin)
    {
        this->x = xin;
        this->y = yin;
    }
    void setPoint(int xin, int yin)
    {
        this->x = xin;
        this->y = yin;   
        
    }
    float getX(){return x;}
    float getY(){return y;}

    void draw()
    {
        glVertex2f(x,y);
    }
};


#endif /* NGON_H */

