//house
#include <glut/GLUT.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the walls of the house
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
        glVertex2f(100.0f, 100.0f);
        glVertex2f(400.0f, 100.0f);
        glVertex2f(400.0f, 400.0f);
        glVertex2f(100.0f, 400.0f);
    glEnd();

    // Draw the roof of the house
    glColor3f(0.9, 0.4, 0.1);
    glBegin(GL_TRIANGLES);
        glVertex2f(100.0f, 400.0f);
        glVertex2f(250.0f, 550.0f);
        glVertex2f(400.0f, 400.0f);
    glEnd();

    // Draw the door of the house
    glColor3f(0.5, 0.2, 0.1);
    glBegin(GL_QUADS);
        glVertex2f(210.0f, 100.0f);
        glVertex2f(290.0f, 100.0f);
        glVertex2f(290.0f, 250.0f);
        glVertex2f(210.0f, 250.0f);
    glEnd();

    // Draw the windows of the house
    glColor3f(0.8, 0.9, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(130.0f, 180.0f);
        glVertex2f(190.0f, 180.0f);
        glVertex2f(190.0f, 240.0f);
        glVertex2f(130.0f, 240.0f);

        glVertex2f(310.0f, 180.0f);
        glVertex2f(370.0f, 180.0f);
        glVertex2f(370.0f, 240.0f);
        glVertex2f(310.0f, 240.0f);
    glEnd();

    // Draw the chimney of the house
    glColor3f(0.6, 0.1, 0.1);
    glBegin(GL_QUADS);
        glVertex2f(300.0f, 420.0f);
        glVertex2f(320.0f, 420.0f);
        glVertex2f(320.0f, 480.0f);
        glVertex2f(300.0f, 480.0f);
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
    gluOrtho2D(0.0, 499.0, 0.0, 599.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("House");

    glutDisplayFunc(display);

    myinit();
    glutMainLoop();
}