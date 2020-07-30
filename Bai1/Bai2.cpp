#include "C:\Users\Administrator\Documents\Visual Studio 2015\Projects\Tuan1\Dependencies\glew\glew.h"
#include "C:\Users\Administrator\Documents\Visual Studio 2015\Projects\Tuan1\Dependencies\freeglut\freeglut.h"

const int screenWidth = 640;
const int screenHeight = 480;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0); // clear black
	glShadeModel(GL_FLAT);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);// Clears the code buffer
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_TRIANGLES);
		glVertex2i(160, 80);
		glVertex2i(480,80);
		glVertex2i(320,400);
	glEnd();

	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
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