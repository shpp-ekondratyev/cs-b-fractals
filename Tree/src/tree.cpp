/*
 * File: tree.cpp
 * ---------------------------
 *
 */

#include <iostream>
#include "gwindow.h"
using namespace std;

/* Global variables/constants */
double treeHeight= 150;
const int branchesCounter = 7;
double theta = 90;

/* Function prototypes */
void drawFractal(GWindow gw,GPoint root,double treeHeight,int branchesCounter,double theta);

int main() {

    GWindow gw (800, 600);
    GPoint root(gw.getWidth()/2,gw.getHeight());

    drawFractal(gw,root,treeHeight,branchesCounter,theta);

    return 0;
}

void drawFractal(GWindow gw,GPoint root,double treeHeight,int branchesCounter,double theta){
    if(branchesCounter <2){
        gw.setColor("GREEN");
    }else{
        gw.setColor("BLACK");
    }
    GPoint top = gw.drawPolarLine(root,treeHeight,theta);

    if(branchesCounter >=0){
        drawFractal(gw,top,treeHeight/1.3,branchesCounter-1,theta - 30);
        drawFractal(gw,top,treeHeight/1.3,branchesCounter-1, theta);
        drawFractal(gw,top,treeHeight/1.3,branchesCounter-1, theta + 30);
    }
}
