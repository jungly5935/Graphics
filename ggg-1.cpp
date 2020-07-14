#include<glut.h>
#include<math.h>
#define Pi 3.1415
void MyDisplay()
{
	GLfloat Size[2], Angle;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0.8, 0.6588);
	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
	glPointSize(Size[0] * 10);
	glBegin(GL_POLYGON);
	for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0) glVertex3f(0.5 * cos(Angle), 0.5 * sin(Angle), 0.0);
	glEnd();
	glFlush();
	
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex3f(-0.15, 0.1, 0.0);
	glVertex3f(0.15, 0.1, 0.0);

	glVertex3f(0.0, -0.008, 0.0);
	glVertex3f(0.0, -0.009, 0.0);
	glVertex3f(0.0, -0.01, 0.0);
	glEnd();


	GLfloat Angle2;
	glColor3f(0.8, 0, 0);
	glTranslatef(0, -0.1, 0);
	glBegin(GL_POLYGON);
	for (Angle2 = Pi; Angle2 <= 2.0 * Pi; Angle2 += Pi / 20.0) glVertex3f(0.2 * cos(Angle2), 0.25 * sin(Angle2), 0);

	glEnd();


	glFlush();

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("ÀÌ¼ö°æ");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}