#include<stdio.h>
#include<GLUT/glut.h>

void drawRect(int x1, int y1, int x2, int y2) {
	glColor3f(1.0, 1.0, 0.0);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	glFlush();
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	glColor3f(1.0, 1.0, 0.0);
	glPointSize(2.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x1, y1);
	glEnd();
	glFlush();
}

void drawLines(int x1, int y1, int x2, int y2) {
	glColor3f(1.0, 1.0, 0.0);
	glPointSize(2.0);
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
	glFlush();
}

void display() {
	glColor3f(1.0, 1.0, 0.0);
	glPointSize(2.0);
	glBegin(GL_POINTS);

	int xi = 300, yi = 200, rx = 200, ry = 100;
	int x = 0, y = ry;
	float p1 = rx * rx * 0.25 + ry * ry - rx * rx * ry;
	int dx = 2 * x * ry * ry, dy = 2 * y * rx * rx;
	while (dx < dy) {
		glVertex2i(x + xi, y + yi);
		glVertex2i(x + xi, -y + yi);
		glVertex2i(-x + xi, -y + yi);
		glVertex2i(-x + xi, y + yi);
		if (p1 < 0) {
			x++;
			dx = 2 * x * ry * ry;
			p1 += dx + ry * ry;
		}
		else {
			x++;
			y--;
			dx = 2 * x * ry * ry;
			dy = 2 * y * rx * rx;
			p1 += dx + ry * ry - dy;
		}
	}
	float p2 = rx * rx * (y - 1) * (y - 1) + ry * ry * (x + 0.5) * (x + 0.5) - rx * rx * ry * ry;
	while (y > 0) {
		glVertex2i(x + xi, y + yi);
		glVertex2i(x + xi, -y + yi);
		glVertex2i(-x + xi, -y + yi);
		glVertex2i(-x + xi, y + yi);
		if (p2 > 0) {
			y--;
			dy = 2 * rx * rx * y;
			p2 = p2 - dy + rx * rx;
		}
		else {
			x++;
			y--;
			dx = dx + 2 * ry * ry;
			dy = dy - 2 * rx * rx;
			p2 = p2 + rx * rx + dx - dy;
		}
	}



	glEnd();
	glFlush();
	int xa = 40;
	int ya = 20;
	drawRect(150 + xa, 120 + ya, 200 + xa, 160 + ya);
	drawRect(360, 220, 410, 260);
	drawTriangle(150 + xa, 220, 200 + xa, 220, 175 + xa, 260);
	drawTriangle(360, 120 + ya, 410, 120 + ya, 385, 160 + ya);
	drawLines(100, 200, 500, 200);
	drawLines(300, 100, 300, 300);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ellipse");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 500, 500);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}