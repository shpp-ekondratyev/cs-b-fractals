/*
 * File: mandelbrot.cpp
 * ---------------------------
 * This program draws the Mandelbrot fractal.
 */
#include <fstream>
#include <iostream>
#include <cmath>
#include "console.h"
#include "gwindow.h"
#include "gbufferedimage.h"

using namespace std;

/* Global variables/constants */
const int imageWidth = 700, imageHeight = 700, maxN = 256;
const double minR = -2.0, maxR = 0.7, minI = -1.2, maxI = 1.3;

/* Function prototypes */
int findMandelbrot(double cr, double ci, int maxIterations);
double mapToReal(int x, int imageWidth, double minR, double maxR);
double mapToImaginary(int y, int imageHeigth, double minI, double maxI);
unsigned long createRGB(int r, int g, int b);

/* Main prograam */
int main(){

    // initialize the outgoing file stream and write the title of the PPM file
    ofstream fout("output-image.ppm");
    fout << "P3" << endl;
    fout << imageWidth << " " << imageHeight << endl;
    fout << "512" << endl;

    GWindow gw;
    gw.setSize(imageWidth, imageHeight);
    GBufferedImage* mandelbrot = new GBufferedImage(0, 0, imageWidth, imageHeight);

    cout << "This program draws the Mandelbrot fractal." << endl;
    cout << "Please wait." << endl;

    // draws the Mandelbrot fractal
    for (int y = 0; y < imageHeight; y++){
        for (int x = 0; x < imageWidth; x++){
            double cr = mapToReal(x, imageWidth, minR, maxR);
            double ci = mapToImaginary(y, imageHeight, minI, maxI);

            int n = findMandelbrot(cr, ci, maxN);

            int r = ((int)(n * sinf(n + 2)) % 256);
            int g = ((n * n) % 256);
            int b = ((n * n) % 256);

            fout << r << " " << g << " " << b << " ";

            mandelbrot->setRGB(x, y, createRGB(r, g, b));

        }
        fout << endl;
    }
    cout << "Mandelbrot fractal saved in the file (output-image.ppm)" << endl;

    gw.add(mandelbrot);

    fout.close();

    cout << "Finished!";

    return(0);
}

int findMandelbrot(double cr, double ci, int maxIterations){
    int i = 0;
    double zr = 0.0, zi = 0.0;
    while (i < maxIterations && zr * zr + zi * zi < 4.0){
        double temp = zr * zr - zi * zi + cr;
        zi = 2.0 * zr * zi + ci;
        zr = temp;
        i++;
    }
    return i;
}

double mapToReal(int x, int imageWidth, double minR, double maxR){
    double range = maxR - minR;
    return x * (range / imageWidth) + minR;
}

double mapToImaginary(int y, int imageHeigth, double minI, double maxI){
    double range = maxI - minI;
    return y * (range / imageHeigth) + minI;
}

unsigned long createRGB(int r, int g, int b){
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}
