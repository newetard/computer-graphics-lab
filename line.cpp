#define GL_SILENCE_DEPRECATION
#include <glut/GLUT.h>
#include <GLUT/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 255.0, 0.0);

    glBegin(GL_LINES);
        glVertex3f(10.0f, 10.0f, 0.0f);
        glVertex3f(50.0f, 50.0f, 0.0f);
    glEnd();
    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    // 10 pixels point size
    glPointSize(10.0);
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