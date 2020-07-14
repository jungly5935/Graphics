#include <glut.h>
#include<math.h>
#define Pi 3.14
GLint gTheta = 0;
GLint gTheta_minute = 0;

GLdouble Angle2 = 0;

void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//�ǿ����ʽð�
	glPushMatrix();

	glColor3f(1, 1, 0);//yellow
	glTranslatef(3, 2, 0);
	glBegin(GL_POLYGON);
	for (Angle2 = 0; Angle2 <= 2.0 * Pi; Angle2 += Pi / 20.0) glVertex3f(0.8 * cos(Angle2), 0.8 * sin(Angle2), 0);
	glEnd();

	glColor3f(1, 0.77, 0.55);
	glBegin(GL_POLYGON);
	for (Angle2 = 0; Angle2 <= 2.0 * Pi; Angle2 += Pi / 20.0) glVertex3f(0.7 * cos(Angle2), 0.7 * sin(Angle2), 0);
	glEnd();

	glPopMatrix();
	
	glColor3f(1, 1, 0); //red
	glBegin(GL_POLYGON);
	glVertex3f(3, 2 + 0.05, 0);
	glVertex3f(3-0.05, 2 - 0.05, 0);
	glVertex3f(3+0.05, 2 - 0.05, 0);
	glEnd();

	glLineWidth(4);
	glColor3f(0.7, 0.988, 0.6);//lime

	glPushMatrix();
	glTranslatef(3, 2, 0);
	glRotatef(gTheta, 0, 0, 1);
	glTranslatef(-3, -2, 0);
	glBegin(GL_LINES); //��ħ
	glVertex3f(3, 2, 0);
	glVertex3f(3, 2.4, 0);
	glEnd();
	glPopMatrix();

	glColor3f(0.2, 0.5, 0.7); //�ϴû�
	glLineWidth(1);
	glPushMatrix();
	glTranslatef(3, 2, 0);
	glRotatef(gTheta_minute, 0, 0, 1);
	glTranslatef(-3, -2, 0);
	glBegin(GL_LINES); //��ħ
	glVertex3f(3, 2, 0);
	glVertex3f(3, 2.7, 0);
	glEnd();
	glPopMatrix();

	
	//�߰� �ð�

	glColor3f(0.77, 0.2, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(0,1, 0); //
	glVertex3f(0.5, 1.5, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(0.5, 0, 0);
	glVertex3f(0, -0.5, 0); //
	glVertex3f(-0.5, 0, 0);
	glVertex3f(-1, 1, 0);
	glVertex3f(-0.5, 1.5, 0);
	glEnd();

	glColor3f(0.55,0.55,0.986744);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3f(0, 0.4, 0);
	glEnd();

	glLineWidth(4); 
	glColor3f(0,0,0); //black

	glPushMatrix();
	glTranslatef(0, 0.4, 0);
	glRotatef(gTheta*2, 0, 0, 1);
	glTranslatef(0, -0.4, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0,0, 0); //��ħ
	glVertex3f(0.1,0.1 ,0);
	glVertex3f(0.2, 0, 0);
	glVertex3f(0, -0.1, 0);
	glVertex3f(-0.2, 0, 0);
	glVertex3f(-0.1, 0.1, 0);


	glEnd();
	glPopMatrix();

	glLineWidth(2);
	glColor3f(1, 1, 1); //white
	
	glPushMatrix();
	glTranslatef(0, 0.4, 0);
	glRotatef(gTheta_minute*2, 0, 0, 1);
	glTranslatef(0, -0.4, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0.4, 0); //��ħ
	glVertex3f(0, 0.9, 0);
	glEnd();
	glPopMatrix();

	//����3�ܽð�
	glColor3f(0.2,0.6,0.998);//blue
	glPushMatrix();
	glTranslatef(-2.5,2 ,0);
	glBegin(GL_POLYGON);
	for (Angle2 = 0; Angle2 <= 2.0 * Pi; Angle2 += Pi / 20.0) glVertex3f(0.8 * cos(Angle2), 0.8 * sin(Angle2), 0);
	glEnd();

	glTranslatef(0, -1.2, 0);
	glBegin(GL_POLYGON);
	for (Angle2 = 0; Angle2 <= 2.0 * Pi; Angle2 += Pi / 20.0) glVertex3f(0.6 * cos(Angle2), 0.6 * sin(Angle2), 0);
	glEnd();

	glTranslatef(0, -0.8, 0);
	glBegin(GL_POLYGON);
	for (Angle2 = 0; Angle2 <= 2.0 * Pi; Angle2 += Pi / 20.0) glVertex3f(0.3 * cos(Angle2), 0.3 * sin(Angle2), 0);
	glEnd();
	glPopMatrix();
	
	glColor3f(0.2, 0, 0.998); //�Ķ���
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex3f(-2.5, 2, 0);
	glEnd();

	
	glColor3f(0.9, 0, 0.9); //����
	glLineWidth(6); //��ħ
	glPushMatrix();
	glTranslatef(-2.5, 2, 0);
	glRotatef(gTheta*0.1, 0, 0, 1);
	glTranslatef(2.5, -2, 0);
	glBegin(GL_LINES);
	glVertex3f(-2.5, 2, 0);
	glVertex3f(-2.5, 2.05, 0);


	glVertex3f(-2.5, 2.1, 0);
	glVertex3f(-2.5, 2.15, 0);



	glEnd();
	glPopMatrix();


	glColor3f(0.9373, 0.6667, 0.9784); //������
	glLineWidth(3); //��ħ
	glPushMatrix();
	glTranslatef(-2.5, 2, 0);
	glRotatef(gTheta_minute*0.1, 0, 0, 1);
	glTranslatef(2.5, -2, 0);
	glBegin(GL_LINES);
	glVertex3f(-2.5, 2, 0);
	glVertex3f(-2.5, 2.1, 0);

	glVertex3f(-2.5, 2.15, 0);
	glVertex3f(-2.5, 2.25, 0);

	glVertex3f(-2.5, 2.3, 0);
	glVertex3f(-2.5, 2.4, 0);

	glEnd();
	glPopMatrix();



	glutSwapBuffers();
} // MyDisplay

void MyTimer(int Value)
{
	gTheta -= 1;
	gTheta_minute -= 10;


	glutPostRedisplay();
	glutTimerFunc(20, MyTimer, 1);
}


int main(int argc, char* * argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("�ð�");
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4, 4, -3, 3, -4, 4);

	glutDisplayFunc(MyDisplay);
	glutTimerFunc(2, MyTimer, 1);

	glutMainLoop();
	return 0;
}
