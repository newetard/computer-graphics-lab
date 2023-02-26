#include <GLUT/glut.h>
#include <math.h>

void display(void)
{
   glClearColor (1.0, 1.0, 1.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);

   // Draw green rectangle for the bottom part of the flag
   glColor3f(0.0, 0.5, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-1.0, -0.5);
   glVertex2f(1.0, -0.5);
   glVertex2f(1.0, -0.2);
   glVertex2f(-1.0, -0.2);
   glEnd();

   // Draw orange rectangle for the top part of the flag
   glColor3f(1.0, 0.5, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-1.0, 0.5);
   glVertex2f(1.0, 0.5);
   glVertex2f(1.0, 0.2);
   glVertex2f(-1.0, 0.2);
   glEnd();

   // Draw blue circle for the Ashoka Chakra
   float theta;
   glColor3f(0.0, 0.0, 1.0);
   glBegin(GL_POLYGON);
   for(int i = 0; i < 360; i++)
   {
      theta = i*3.142/180;
      glVertex2f(0.0f + 0.15f*cos(theta), 0.0f + 0.15f*sin(theta));
   }
   glEnd();

   // Draw 24 spokes for the Ashoka Chakra
   glColor3f(1.0, 1.0, 1.0);
   glLineWidth(2.0);
   glBegin(GL_LINES);
   for(int i = 0; i < 24; i++)
   {
      theta = i*15*3.142/180;
      glVertex2f(0.0f, 0.0f);
      glVertex2f(0.0f + 0.15f*cos(theta), 0.0f + 0.15f*sin(theta));
   }
   glEnd();

   glFlush ();
}

void init(void)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Indian Flag");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
