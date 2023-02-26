#include <GL/glut.h>
#include <iostream>
using namespace std;

// function to draw a pixel at (x, y)
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// function to draw a circle using midpoint circle algorithm
void drawCircle(int x0, int y0, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    while (x <= y) {
        drawPixel(x + x0, y + y0);
        drawPixel(-x + x0, y + y0);
        drawPixel(x + x0, -y + y0);
        drawPixel(-x + x0, -y + y0);
        drawPixel(y + x0, x + y0);
        drawPixel(-y + x0, x + y0);
        drawPixel(y + x0, -x + y0);
        drawPixel(-y + x0, -x + y0);
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

// function to display the OpenGL window
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);

    // draw a circle centered at (250, 250) with radius 100
    drawCircle(250, 250, 100);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle using midpoint circle algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
