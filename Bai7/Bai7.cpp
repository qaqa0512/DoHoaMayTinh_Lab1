#include "C:\Users\Administrator\Documents\Visual Studio 2015\Projects\Tuan1\Dependencies\glew\glew.h"
#include "C:\Users\Administrator\Documents\Visual Studio 2015\Projects\Tuan1\Dependencies\freeglut\freeglut.h"

const int screenWidth = 640;
const int screenHeight = 480;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0); // clear black
}

void drawRectangle(GLint x, GLint y, GLint width, GLint height) {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 1.0f); // dinh mau huong
	glVertex2i(x, y);// (tren, phai)...
	glColor3f(0.0f, 1.0f, 1.0f);// dinh mau xanh da troi
	glVertex2i(x + width, y);// (tren, phai)
	glColor3f(1.0f, 1.0f, 0.0f);// dinh mau xanh vang
	glVertex2i(x + width, y + height);// (duoi, phai)
	glColor3f(1.0f, 1.0f, 1.0f);// dinh mau trang
	glVertex2i(x, y + height); // (duoi, trai)
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);// Clears the code buffer
	GLint w = 400, h = 200; // chieu rong = 400, chieu cao = 200
	GLint x = (screenWidth - w) / 2; // canh vao giua man hinh
	GLint y = (screenHeight - h) / 2; // canh vao giua theo y
	drawRectangle(x, y, w, h);

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