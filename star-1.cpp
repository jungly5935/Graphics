
#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 1.0);
	glBegin(GL_POLYGON);

	glVertex3f(-0.2, -0.2, 0.0); //glvertex 인수(3) 자료형(f) (a,b,c)
	glVertex3f(-0.15, 0.1, 0.0);
	glVertex3f(-0.4, -0.1, 0.0);
	glVertex3f(-0.7, 0, 0.0);
	glVertex3f(-0.65, -0.25, 0.0);
	glVertex3f(-0.9, -0.5, 0.0);
	glVertex3f(-0.6, -0.5, 0.0);
	glVertex3f(-0.3, -0.9, 0.0);
	glVertex3f(-0.25, -0.5, 0.0);
	glVertex3f(0.2, -0.5, 0.0);

	glEnd();

	glColor3f(1.0, 0, 0.5);
	glBegin(GL_POLYGON);

	glVertex3f(0.7, 0.6, 0.0); //glvertex 인수(3) 자료형(f) (a,b,c)
	glVertex3f(0.72, 0.65, 0.0);
	glVertex3f(0.6, 0.62, 0.0);
	glVertex3f(0.55, 0.65, 0.0);
	glVertex3f(0.58, 0.6, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.59, 0.5, 0.0);
	glVertex3f(0.6, 0.4, 0.0);
	glVertex3f(0.68, 0.5, 0.0);
	glVertex3f(0.75, 0.51, 0.0);

	glEnd();


	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 300);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("별 그리기");
	glClearColor(1, 1, 0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
이수경, 3월 18일 오전 12:59
#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 1.0);
	glBegin(GL_POLYGON);

	glVertex3f(-0.2, -0.2, 0.0); //glvertex 인수(3) 자료형(f) (a,b,c)
	glVertex3f(-0.15, 0.1, 0.0);
	glVertex3f(-0.4, -0.1, 0.0);
	glVertex3f(-0.7, 0, 0.0);
	glVertex3f(-0.65, -0.25, 0.0);
	glVertex3f(-0.9, -0.5, 0.0);
	glVertex3f(-0.6, -0.5, 0.0);
	glVertex3f(-0.3, -0.9, 0.0);
	glVertex3f(-0.25, -0.5, 0.0);
	glVertex3f(0.2, -0.5, 0.0);

	glEnd();

	glColor3f(1.0, 0, 0.5);
	glBegin(GL_POLYGON);

	glVertex3f(0.7, 0.6, 0.0); //glvertex 인수(3) 자료형(f) (a,b,c)
	glVertex3f(0.72, 0.65, 0.0);
	glVertex3f(0.6, 0.62, 0.0);
	glVertex3f(0.55, 0.65, 0.0);
	glVertex3f(0.58, 0.6, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.59, 0.5, 0.0);
	glVertex3f(0.6, 0.4, 0.0);
	glVertex3f(0.68, 0.5, 0.0);
	glVertex3f(0.75, 0.51, 0.0);

	glEnd();


	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 300);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("별 그리기");
	glClearColor(1, 1, 0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}