#include <glut.h>
#include <stdio.h>
#include <math.h>
int gCount = 0; //마우스 클릭한 개수 (snow 개수)
float gSnowX, gSnowY;
#define Pi 3.1415

void MyDisplay() {

	printf("d \n");

	
	glColor3f(0.955, 0.7, 0.899);
	if(gCount == 0)glClear(GL_COLOR_BUFFER_BIT);

	if (gCount > 0) {
		
		glColor3f(0.955, 0.7, 0.899);
		glBegin(GL_POLYGON);
		glVertex3f(gSnowX, gSnowY, 0);
		glVertex3f(gSnowX - 0.025, gSnowY + 0.045, 0);
		glVertex3f(gSnowX + 0.025, gSnowY + 0.045, 0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(gSnowX-0.01, gSnowY-0.01, 0);
		glVertex3f(gSnowX - 0.06, gSnowY - 0.015, 0);
		glVertex3f(gSnowX -0.04, gSnowY -0.06, 0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(gSnowX+0.01, gSnowY-0.01, 0);
		glVertex3f(gSnowX +0.06, gSnowY - 0.015, 0);
		glVertex3f(gSnowX + 0.04, gSnowY -0.06, 0);
		glEnd();

		glColor3f(1,1,0);
		glPointSize(3.0);
		glBegin(GL_POINTS);
		glVertex3f(gSnowX + 0.01, gSnowY - 0.01, 0);
		glVertex3f(gSnowX - 0.01, gSnowY - 0.01, 0);
		glVertex3f(gSnowX , gSnowY + 0.01, 0);
		glEnd();



		glColor3f(0.955, 0.7, 0.899);
		glBegin(GL_POLYGON);
		glVertex3f(gSnowX -0.1, gSnowY -0.1, 0);
		glVertex3f(gSnowX - 0.025 -0.1, gSnowY + 0.045 -0.1, 0);
		glVertex3f(gSnowX + 0.025 -0.1, gSnowY + 0.045 -0.1, 0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(gSnowX - 0.01 -0.1, gSnowY - 0.01 -0.1, 0);
		glVertex3f(gSnowX - 0.06 -0.1, gSnowY - 0.015 -0.1, 0);
		glVertex3f(gSnowX - 0.04 -0.1, gSnowY - 0.06 -0.1, 0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(gSnowX + 0.01 -0.1, gSnowY - 0.01 -0.1, 0);
		glVertex3f(gSnowX + 0.06 -0.1, gSnowY - 0.015 -0.1, 0);
		glVertex3f(gSnowX + 0.04 -0.1, gSnowY - 0.06 -0.1, 0);
		glEnd();

		glColor3f(1, 1, 0);
		glPointSize(3.0);
		glBegin(GL_POINTS);
		glVertex3f(gSnowX + 0.01 -0.1, gSnowY - 0.01 -0.1, 0);
		glVertex3f(gSnowX - 0.01 -0.1, gSnowY - 0.01 -0.1, 0);
		glVertex3f(gSnowX -0.1, gSnowY + 0.01 -0.1, 0);
		glEnd();


		glColor3f(0.955, 0.7, 0.899);
		glBegin(GL_POLYGON);
		glVertex3f(gSnowX +0.1, gSnowY -0.1, 0);
		glVertex3f(gSnowX - 0.025 +0.1, gSnowY + 0.045 -0.1, 0);
		glVertex3f(gSnowX + 0.025 +0.1, gSnowY + 0.045 -0.1, 0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(gSnowX - 0.01 +0.1, gSnowY - 0.01 -0.1, 0);
		glVertex3f(gSnowX - 0.06 +0.1, gSnowY - 0.015 -0.1, 0);
		glVertex3f(gSnowX - 0.04 +0.1, gSnowY - 0.06 -0.1, 0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(gSnowX + 0.01 +0.1, gSnowY - 0.01 -0.1, 0);
		glVertex3f(gSnowX + 0.06 +0.1, gSnowY - 0.015 -0.1, 0);
		glVertex3f(gSnowX + 0.04 +0.1, gSnowY - 0.06 -0.1, 0);
		glEnd();

		glColor3f(1, 1, 0);
		glPointSize(3.0);
		glBegin(GL_POINTS);
		glVertex3f(gSnowX + 0.01 +0.1, gSnowY - 0.01 -0.1, 0);
		glVertex3f(gSnowX - 0.01 +0.1, gSnowY - 0.01 -0.1, 0);
		glVertex3f(gSnowX +0.1, gSnowY + 0.01 -0.1, 0);
		glEnd();


	}

	glFlush();
}



void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {

	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {

		gSnowX = (2* X / 600.0) - 1;
		gSnowY = (2*(600 - Y) / 600.0) - 1;
		gCount++;
		printf("count: %d (%d, %d) (%g, %g) \n", gCount, X, Y, gSnowX, gSnowY);

	}
	glutPostRedisplay();
}

void MyInit() {
	glClearColor(0.642, 0.8613, 0.9966, 1);
	glOrtho(-1, 1, -1, 1, -1, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(450, 0);
	glutCreateWindow("벚꽃이 피어나요");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();

	return 0;
}