#include <glut.h>
GLfloat Delta = 0.0;
GLfloat Delta2 = 0.0;
char gDirection = 'U';
char gDirection2 = 'D';

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.4859,0.67484 , 0.8737, 1.0);
	glColor3f(1.0, 0, 1.0);
	glBegin(GL_POLYGON);

	glVertex3f(-0.2, -0.2+Delta, 0.0); //glvertex 인수(3) 자료형(f) (a,b,c)
	glVertex3f(-0.15, 0.1 + Delta, 0.0);
	glVertex3f(-0.4, -0.1 + Delta, 0.0);
	glVertex3f(-0.7, 0 + Delta, 0.0);
	glVertex3f(-0.65, -0.25 + Delta, 0.0);
	glVertex3f(-0.9, -0.5 + Delta, 0.0);
	glVertex3f(-0.6, -0.5 + Delta, 0.0);
	glVertex3f(-0.3, -0.9 + Delta, 0.0);
	glVertex3f(-0.25, -0.5 + Delta, 0.0);
	glVertex3f(0.2, -0.5 + Delta, 0.0);

	glEnd();

	glColor3f(1.0, 1.0, 0.5);
	glBegin(GL_POLYGON);

	glVertex3f(0.7, 0.6+Delta2, 0.0); //glvertex 인수(3) 자료형(f) (a,b,c)
	glVertex3f(0.72, 0.65 + Delta2, 0.0);
	glVertex3f(0.6, 0.62 + Delta2, 0.0);
	glVertex3f(0.55, 0.65 + Delta2, 0.0);
	glVertex3f(0.58, 0.6 + Delta2, 0.0);
	glVertex3f(0.5, 0.5 + Delta2, 0.0);
	glVertex3f(0.59, 0.5 + Delta2, 0.0);
	glVertex3f(0.6, 0.4 + Delta2, 0.0);
	glVertex3f(0.68, 0.5 + Delta2, 0.0);
	glVertex3f(0.75, 0.51 + Delta2, 0.0);

	glEnd();
	glutSwapBuffers();
}
void MyTimer(int Value) {

	if (gDirection == 'U')
	{
		Delta = Delta + 0.01;
		if (Delta > 3.0)gDirection = 'D';
	}
	else if (gDirection == 'D') {
		Delta = Delta - 0.01;
		if (Delta < 0) gDirection = 'U';
	}

	if (gDirection2 == 'D')
	{
		Delta2 = Delta2 - 0.01;
		if (Delta2 < -3)gDirection2 = 'U';
	}
	else if (gDirection2 == 'U') {
		Delta2 = Delta2 + 0.01;
		if (Delta2 > 0) gDirection2 = 'D';
	}


	glutPostRedisplay();
	glutTimerFunc(2, MyTimer, 1);
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300); 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Timer Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(2, MyTimer, 1);
	glutMainLoop();
	return 0;
}
