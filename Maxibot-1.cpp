#include <stdlib.h> 
#include <glut.h>
static int shoulder_B = -10, elbow_B = 50;
static int shoulder = 10, elbow = -50;



void init(void) {
	glClearColor(0, 0, 0, 1);
	glShadeModel(GL_FLAT);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0,1.2, 0);           
	glutWireSphere(0.6, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);           
	glScalef(1.2,1.5, 1);
	glutWireCube(1);
	glPopMatrix();


	glPushMatrix(); // 오른쪽 (RED) 팔 전체 Push---------------------------
	glColor3f(0.8866, 0.23, -.43);
		glTranslatef(0.6, 0.5, 0);           // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)shoulder_B, 0, 0, 1);     // 원점 기준 회전
		glTranslatef(0.6, 0, 0);              // Pivot을 원점으로 이동 

		glPushMatrix();     // 원점을 기준으로 객체 생성 및 축소/확대
			glScalef(1.2, 0.4, 1);
			glutWireCube(1);   //팔 상부
			glPopMatrix();
	
		glTranslatef(0.6, 0, 0);             // Pivot 지정 및 객체 이동 
		glRotatef((GLfloat)elbow_B, 0, 0, 1);         // 원점 기준 회전
		glTranslatef(0.6, 0, 0);               // Pivot을 원점으로 이동
	
		glPushMatrix();      // 원점을 기준으로 객체 생성 및 축소/확대
			glScalef(1.2, 0.4, 1);
			glutWireCube(1);  // 팔 하부
	
		glPopMatrix();
	glPopMatrix(); //팔 전체 끝


	glPushMatrix(); // 왼쪽 팔 전체 Push---------------------------
	glTranslatef(-0.6, 0.5, 0);           // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)shoulder, 0, 0, 1);     // 원점 기준 회전
	glTranslatef(-0.6, 0, 0);              // Pivot을 원점으로 이동 

	glPushMatrix();     // 원점을 기준으로 객체 생성 및 축소/확대
		glColor3f(1, 1, 1);
		glScalef(1.2, 0.4, 1);
		glutWireCube(1);   //팔 상부
	glPopMatrix();

	glTranslatef(-0.6, 0, 0);             // Pivot 지정 및 객체 이동 
	glRotatef((GLfloat)elbow, 0, 0, 1);         // 원점 기준 회전
	glTranslatef(-0.6, 0, 0);               // Pivot을 원점으로 이동

	glPushMatrix();      // 원점을 기준으로 객체 생성 및 축소/확대
		glColor3f(1, 1, 1);
		glScalef(1.2, 0.4, 1);
		glutWireCube(1);  // 팔 하부

	glPopMatrix();
	glPopMatrix(); //팔 전체 끝




	glutSwapBuffers();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65, (GLfloat)w / (GLfloat)h, 1, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -5);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'r': shoulder = (shoulder + 5) % 360; break;
	case 'e': shoulder = (shoulder - 5) % 360; break;
	case 'R': elbow = (elbow + 5) % 360; break;
	case 'E': elbow = (elbow - 5) % 360; break;
	
	case 'p': shoulder_B = (shoulder_B + 5) % 360; break;
	case 'o': shoulder_B = (shoulder_B - 5) % 360; break;
	case 'P': elbow_B = (elbow_B + 5) % 360; break;
	case 'O': elbow_B = (elbow_B - 5) % 360; break;


	case 27: exit(0); break;
	default: break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Robot Arm");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
