#include <glut.h>

GLUquadricObj* q = gluNewQuadric();

void MyDisplay()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0, 0.0, 1.0);
	glutSolidTeapot(1.0);


	glColor3f(1.0, 1.0, 0.0);
	gluQuadricDrawStyle(q, GLU_FILL);
	gluSphere(q, 0.7, 50, 50);

	glColor3f(1.0, 0.0, 0.0);
	glutWireTeapot(0.6);



	glutSwapBuffers();


}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("GLU및 GLUT사용해보기");
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glOrtho(-2,2,-2,2,-2,2);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}