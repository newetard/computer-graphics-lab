
#include <GLUT/glut.h>

void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * 3.14159265358979323846f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Red light
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(0.0, 0.0, 1.0);

    // Yellow light
    glColor3f(1.0, 1.0, 0.0);
    drawCircle(0.0, 2.0, 1.0);

    // Green light
    glColor3f(0.0, 1.0, 0.0);
    drawCircle(0.0, -2.0, 1.0);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Traffic Light");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


#define GL_SILENCE_DEPRECATION
#include <glut/GLUT.h>
#include <GLUT/glut.h>

int rx,ry;//semi-Major axis & semi Minor Axis
int xCenter,yCenter;//center of ellipse


void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    // 10 pixels point size
    glPointSize(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0); 
     glBegin(GL_QUADS);
        //glVertex3f(300.0f, 210.0f, 0.0f);
        //glVertex3f(340.0f, 215.0f, 0.0f);
        //glVertex3f(320.0f, 250.0f, 0.0f);
        glVertex3f(100.0f, 100.0f, 0.0f);
        glVertex3f(100.0f, 400.0f, 0.0f);
        glVertex3f(200.0f, 400.0f, 0.0f);
        glVertex3f(200.0f, 100.0f, 0.0f);
     glEnd();

     // First ellipse parameters
     glColor3f(1.0, 0.0, 0.0);
     int xCenter1 = 150;
     int yCenter1 = 150;
     int rx1 = 30;
     int ry1 = 30;

     // Second ellipse parameters
     glColor3f(0.0, 1.0, 0.0);
     int xCenter2 = 150;
     int yCenter2 = 250;
     int rx2 = 30;
     int ry2 = 30;

     glColor3f(0.0, 0.0, 1.0);
     int xCenter3 = 150;
     int yCenter3 = 350;
     int rx3 = 30;
     int ry3 = 30;

     // Array of ellipse parameters
     int ellipseParams[3][4] = {{xCenter1, yCenter1, rx1, ry1}, {xCenter2, yCenter2, rx2, ry2}};

     // Loop through the array and draw each ellipse
     for (int i = 0; i < 2; i++) {
         xCenter = ellipseParams[i][0];
         yCenter = ellipseParams[i][1];
         rx = ellipseParams[i][2];
         ry = ellipseParams[i][3];
         ellipseMidPoint();
     }

    
    glEnd();
    glFlush();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Simple Window");

    glutDisplayFunc(display);

    myinit();
    glutMainLoop();
}
