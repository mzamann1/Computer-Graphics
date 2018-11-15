/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   color.h
 * Author: panther
 *
 * Created on October 16, 2018, 11:36 PM
 */

#ifndef COLOR_H
#define COLOR_H

#include <GL/gl.h>

class color
{
private:
    float red, green, blue;
public:
    color()
    {
        red, green, blue = 0.0;
        
    }
    float getR()
    {
        return red;
    }
    float getG()
    {
        return green;
    }
    float getB()
    {
        return blue;
    }
    void setColor(float r,float g,float b)
    {
        red = r;
        green = g;
        blue = b;
 
    }
};
#endif /* COLOR_H */


