#include "C:\Users\Administrator\Documents\Visual Studio 2015\Projects\Tuan1\Dependencies\glew\glew.h"
#include "C:\Users\Administrator\Documents\Visual Studio 2015\Projects\Tuan1\Dependencies\freeglut\freeglut.h"

const int screenWidth = 640;
const int screenHeight = 480;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0); // clear white
}

void drawSquare(GLint x, GLint y, GLint a) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0); // mau do
	glVertex2i(x, y);
	glColor3f(0.0, 1.0, 0.0);// mau xanh duong
	glVertex2i(x + a, y);
	glColor3f(0.0, 0.0, 1.0);// mau xanh la
	glVertex2i(x + a, y + a);
	glVertex2i(x, y + a);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);// Clears the code buffer
	GLint size = 200; // do dai canh = 200
	GLint x = (screenWidth - size) / 2; // canh vao giua theo x
	GLint y = (screenHeight - size) / 2; // canh vao giua theo y
	drawSquare(x, y, size);

	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);// Khoi tao glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// Khoi tao che do ve single buffer va he mau RGB
	glutInitWindowSize(screenWidth, screenHeight); //optional
	glutInitWindowPosition(100, 100); //optional
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;

}