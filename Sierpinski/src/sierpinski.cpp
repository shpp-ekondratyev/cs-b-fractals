/*
 * File: sierpinski.cpp
 * ---------------------------
 *
 */

#include <iostream>
#include "gwindow.h"
#include <cmath>

using namespace std;

/* Function prototypes */
void drawTriangle(GWindow window, GPoint top, double EDGE_LENGTH, int cycleCount);

/* Global variables/constants */
const double EDGE_LENGTH = 314; // size of the triangle side at start
int cycleCount = 0; //start number of triangles in triangle

/* Main program*/
int main() {

    GWindow window (800, 600);
    GPoint top(window.getWidth() / 2,window.getHeight() / 2-((sqrt(3) * EDGE_LENGTH) / 2) / 2);

    drawTriangle (window,top,EDGE_LENGTH,cycleCount);

    return 0;
}

void drawTriangle(GWindow window, GPoint top, double EDGE_LENGTH, int cycleCount){

    double height = sqrt(3) * EDGE_LENGTH / 2;

    double topX = top.getX();
    double topY = top.getY();

    GPoint left(topX - height,topY + height);
    GPoint right(topX + height,topY + height);

    window.drawLine(top,left);
    window.drawLine(left,right);
    window.drawLine(top,right);

    if(cycleCount != 10){

        GPoint left(topX - height / 2,topY + height / 2);
        GPoint right(topX + height / 2,topY + height / 2);

        drawTriangle(window,top,EDGE_LENGTH / 2,cycleCount + 1);
        drawTriangle(window,left,EDGE_LENGTH / 2,cycleCount + 1);
        drawTriangle(window,right,EDGE_LENGTH / 2,cycleCount + 1);
    }

}
