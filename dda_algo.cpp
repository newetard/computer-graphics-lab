#define GL_SILENCE_DEPRECATION
#include<GLUT/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;
 
void display(void)
{
    float dy,dx,step,x,y,k,Xin,Yin;
    dx=x2-x1;
    dy=y2-y1;
 
 if(abs(dx)> abs(dy))
 {
    step = abs(dx);
    }
    else
    step = abs(dy);
 
 Xin = dx/step;
 Yin = dy/step;
 
 x= x1;
 y=y1;
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
 
 for (k=1 ;k<=step;k++)
 {x= x + Xin;
 y= y + Yin;
 
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
 }
 
 
glFlush();
}
 
void init(void)
{
glClearColor(0.7,0.7,0.7,0.7);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}
 
int main(int argc, char** argv) {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);
 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA Line Algo");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}


/*
#define GL_SILENCE_DEPRECATION
#include<GLUT/glut.h>
#include<stdlib.h>
#include<stdio.h>

#include <math.h>

class Point {
public:
    float x;
    float y;

    Point(float x, float y): x(x), y(y) {}
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    // get points x and y
    Point a(100.0f, 400.0f);
    Point b(400.0f, 200.0f);

    // calculate dx and dy
    float dX = b.x - a.x;
    float dY = b.y - a.y;

    // calculate steps
    float steps;
    if (abs(dX) > abs(dY)) {
        steps = abs(dX);
    } else {
        steps = abs(dY);
    }

    // calculate X and Y increments
    float Xincrement = dX / (steps);
    float Yincrement = dY / (steps);

    // starting point
    float x = a.x;
    float y = a.y;

    glBegin(GL_POINTS);
        for(int i = 0; i < steps; i++) {
            glVertex2f(round(x), round(y));
            x += Xincrement;
            y += Yincrement;
        }
    glEnd();
    glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
    // 10 pixels point size
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Simple Window");

    glutDisplayFunc(display);

    myinit();
    glutMainLoop();
}

/**/