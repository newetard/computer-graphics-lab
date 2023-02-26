#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include<iostream>
using namespace std;
int rx,ry;//semi-Major axis & semi Minor Axis
int xCenter,yCenter;//center of ellipse


void myinit(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glColor3f(1.0, 0.0, 0.0);
 glPointSize(10.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D (0.0,640.0,0.0,480.0);
 }
 void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
}

void ellipseMidPoint()
{
    //int xCenter = 250;
    //int yCenter = 300;
    //int rx = 200;
    //int ry = 200;

    //plotting for 1st region of 1st quardant and the slope will be < -1
     //----------------------Region-1------------------------//
    float x = 0;
    float y = ry;//(0,ry) ---
    float p1 = ry * ry - (rx * rx)* ry + (rx * rx) * (0.25) ;
    //slope
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    while(dx < dy)
    {
        //plot (x,y)
         setPixel(xCenter + x  ,  yCenter+y);
         setPixel( xCenter - x,   yCenter + y);
         setPixel( xCenter + x  , yCenter - y );
         setPixel( xCenter - x  , yCenter - y);
        if(p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx =  2 * (ry * ry) * x;
            dy =  2 * (rx * rx) * y;
             p1 = p1 + dx - dy +(ry * ry);
        }
    }
    //ploting for 2nd region of 1st quardant and the slope will be > -1
     //----------------------Region-2------------------------//
    float p2 = (ry * ry )* ( x +  0.5) * ( x +  0.5) +  ( rx * rx) * ( y - 1) * ( y - 1) - (rx * rx )* (ry * ry);


    while(y > 0)
    {
        //plot (x,y)
         setPixel(xCenter + x  ,  yCenter+y);
         setPixel( xCenter - x,   yCenter + y);
         setPixel( xCenter + x  , yCenter - y );
         setPixel( xCenter - x  , yCenter - y);     //glEnd();
        if(p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            //dy = 2 * rx * rx *y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx) ;
            dx = dx + 2 * (ry * ry) ;
            p2 = p2 + dx -
            dy + (rx * rx);
        }
    }

}


void display()
{
    
     glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
     glColor3f(1.0,0.0,0.0);          // red foreground
     glPointSize(2.0);               // size of points to be drawin (in pixel)
     glBegin(GL_LINES);
        glVertex3f(100.0f, 50.0f, 0.0f);
        glVertex3f(110.0f, 200.0f, 0.0f);

     glBegin(GL_LINES);
        glVertex3f(60.0f, 50.0f, 0.0f);
        glVertex3f(50.0f, 200.0f, 0.0f);   
     //establish a coordinate system for the image
     //establish a coordinate system for the image

     // First ellipse parameters
     int xCenter1 = 80;
     int yCenter1 = 50;
     int rx1 = 20;
     int ry1 = 5;

     // Second ellipse parameters
     int xCenter2 = 80;
     int yCenter2 = 200;
     int rx2 = 30;
     int ry2 = 10;

     // Array of ellipse parameters
     int ellipseParams[2][4] = {{xCenter1, yCenter1, rx1, ry1}, {xCenter2, yCenter2, rx2, ry2}};

     // Loop through the array and draw each ellipse
     for (int i = 0; i < 2; i++) {
         xCenter = ellipseParams[i][0];
         yCenter = ellipseParams[i][1];
         rx = ellipseParams[i][2];
         ry = ellipseParams[i][3];
         ellipseMidPoint();
     }

     glBegin(GL_TRIANGLES);
        //glVertex3f(300.0f, 210.0f, 0.0f);
        //glVertex3f(340.0f, 215.0f, 0.0f);
        //glVertex3f(320.0f, 250.0f, 0.0f);
        glVertex3f(80.0f, 100.0f, 0.0f);
        glVertex3f(85.0f, 120.0f, 0.0f);
        glVertex3f(90.0f, 80.0f, 0.0f);


     glEnd();
     glFlush(); // send all output to the display
}


int main(int argc,char** argv)
{
    cout<<"\n\nEnter Center Of Ellipse  \n\n";
    cout<<"\n x = ";
    cin>>xCenter;

    cout<<"\n y = ";
    cin>>yCenter;

    cout<<" Enter a Semi Major Axix : ";
    cin>>rx;
    cout<<" \nEnter a Semi Minor Axis: ";
    cin>>ry;
	glutInit(&argc,argv);
    glutInitWindowSize(640,480); // set the size of the window
    glutInitWindowPosition(10,10); // the position of the top-left of window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
	myinit();
    glutDisplayFunc(display); // set the gl display callback function
    glutMainLoop(); // enter the GL event loop

}

