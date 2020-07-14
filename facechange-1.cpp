#include <glut.h>
#include<math.h>
#define Pi 3.1415
unsigned char gKey = 'u';
float gX, gY; // int ¾È‰Î

void MyDisplay() {

	GLfloat Size[2], Angle;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glClear(GL_COLOR_BUFFER_BIT); //¹ÙÅÁ»ö Àû¿ë
	
								  
	//¾ó±¼
	glColor3f(1, 0.8, 0.6588); 
	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
	glPointSize(Size[0] * 10);
	glBegin(GL_POLYGON);
	for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0) glVertex3f(0.5 * cos(Angle), 0.5 * sin(Angle), 0.0);
	glEnd();

	if (gKey == 'u') {
	
		//´«½ç
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-0.2, 0.15, 0.0);
		glVertex3f(-0.1, 0.15, 0.0);

		glVertex3f(0.1, 0.15, 0.0);
		glVertex3f(0.2, 0.15, 0.0);

		glEnd();


		//´«
		glColor3f(0, 0, 0);
		glBegin(GL_POINTS);
		glVertex3f(-0.15, 0.1, 0.0);
		glVertex3f(0.15, 0.1, 0.0);
		glEnd();

		//ÄÚ
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.05, 0.0);
		glVertex3f(0.0, -0.1, 0.0);
		glEnd();

		//ÀÔ
		glColor3f(0.8, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-0.2, -0.2, 0.0);
		glVertex3f(0.2, -0.2, 0.0);

		glEnd();
		

	}
	else if (gKey == 'h') //¿ôÀ½
	{
	
		//´«½ç
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-0.2, 0.2, 0.0);
		glVertex3f(-0.1, 0.2, 0.0);

		glVertex3f(0.1, 0.2, 0.0);
		glVertex3f(0.2, 0.2, 0.0);

		glEnd();


		//´«
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-0.2, 0.1, 0.0);
		glVertex3f(-0.15, 0.15, 0.0);
		glVertex3f(-0.15, 0.15, 0.0);
		glVertex3f(-0.1, 0.1, 0.0);


		glVertex3f(0.1, 0.1, 0.0);
		glVertex3f(0.15, 0.15, 0.0);
		glVertex3f(0.15, 0.15, 0.0);
		glVertex3f(0.2, 0.1, 0.0);


		glEnd();

		//ÄÚ
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.05, 0.0);
		glVertex3f(0.0, -0.1, 0.0);
		glEnd();

		//ÀÔ
		GLfloat Angle2;
		glColor3f(0.8, 0, 0);

		glBegin(GL_POLYGON);
		for (Angle2 = Pi; Angle2 <= 2.0 * Pi; Angle2 += Pi / 20.0) glVertex3f(0.2 * cos(Angle2), 0.25 * sin(Angle2), 0);

		glEnd();
	}
	else if (gKey == 's') //½½ÇÄ
	{
	
	//´«½ç
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-0.2, 0.1, 0.0);
	glVertex3f(-0.1, 0.15, 0.0);

	glVertex3f(0.1, 0.15, 0.0);
	glVertex3f(0.2, 0.1, 0.0);

	glEnd();

	//´«¹°

	glColor3f(0, 0, 0.9);
	glBegin(GL_LINES);

	glVertex3f(-0.15, 0.1, 0.0);
	glVertex3f(-0.15, -0.1, 0.0);

	glVertex3f(0.15, 0.1, 0.0);
	glVertex3f(0.15, -0.1, 0.0);
	glEnd();

	//´«
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex3f(-0.15, 0.08, 0.0);
	glVertex3f(0.15, 0.08, 0.0);
	glEnd();



	//ÄÚ
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.05, 0.0);
	glVertex3f(0.0, -0.1, 0.0);
	glEnd();

	//ÀÔ
	glColor3f(0.8, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-0.2, -0.25, 0.0);
	glVertex3f(0, -0.15, 0.0);
	glVertex3f(0, -0.15, 0.0);
	glVertex3f(0.2, -0.25, 0.0);

	glEnd();
	
	}
	else if (gKey == 'a') //È­³²
	{
	//´«½ç
	glLineWidth(3.0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-0.1, 0.1, 0.0);
	glVertex3f(-0.2, 0.15, 0.0);
	
	glVertex3f(0.2, 0.15, 0.0);
	glVertex3f(0.1, 0.1, 0.0);

	glEnd();

	//´«
	glLineWidth(1.0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-0.2, 0.08, 0.0);
	glVertex3f(-0.1, 0.08, 0.0);
	
	glVertex3f(0.1, 0.08, 0.0);
	glVertex3f(0.2, 0.08, 0.0);

	glEnd();

	//ÄÚ
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.05, 0.0);
	glVertex3f(0.0, -0.1, 0.0);
	glEnd();

	//ÀÔ
	glColor3f(0.8, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.2, -0.3, 0.0);
	glVertex3f(0.2, -0.3, 0.0);
	glVertex3f(0.2, -0.1, 0.0);
	glVertex3f(-0.2, -0.1, 0.0);

	glEnd();
	
	}
	
	//º°
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);

	glVertex3f(0.7+gX, 0.6+gY, 0.0);
	glVertex3f(0.72 + gX, 0.65 + gY, 0.0);
	glVertex3f(0.6 + gX, 0.62 + gY, 0.0);
	glVertex3f(0.55 + gX, 0.65 + gY, 0.0);
	glVertex3f(0.58 + gX, 0.6 + gY, 0.0);
	glVertex3f(0.5 + gX, 0.5 + gY, 0.0);
	glVertex3f(0.59 + gX, 0.5 + gY, 0.0);
	glVertex3f(0.6 + gX, 0.4 + gY, 0.0);
	glVertex3f(0.68 + gX, 0.5 + gY, 0.0);
	glVertex3f(0.75 + gX, 0.51 + gY, 0.0);

	glEnd();



	glFlush();

	glutSwapBuffers();
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'h': 
		
	case 's': 
		 
	case 'a': 

	case 'u': gKey = key; break;
	case 'B': glClearColor(1, 0.6882, 0.6961, 1); break;
	case 'P': glClearColor(1, 0, 1, 1); break;
	case 'M': glClearColor(0, 1, 1, 1); break;


	}
	glutPostRedisplay(); // ÀÌ°Ô¾øÀ¸¸é g, w´­·¶À»¶§ ¹Ù·Î »ö ¹Ù²îÁö ¾Ê°í È­¸é Å©±â Á¶Á¤ÇØ¾ß ¹Ù²ñ
}void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		gX -= 0.1; break;
	case GLUT_KEY_RIGHT:
		gX += 0.1;break;
	case GLUT_KEY_DOWN:
		gY -= 0.1; break;
	case GLUT_KEY_UP:
		gY += 0.1; break;
	
	case GLUT_KEY_F5:
		gX = 0; gY = 0;
		break;
	}
	glutPostRedisplay();
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.5, 0.5, 0.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
}

void MyReshape(int NewWidth, int NewHeight) {
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0 , 1.0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB |GL_DOUBLEBUFFER);
		glutInitWindowSize(300, 300);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("h:¿ôÀ½, s:½½ÇÄ, a:È­³², B:ºÐÈ«»ö, P:º¸¶ó»ö, M:¹ÎÆ®»ö");
		MyInit();
		glutDisplayFunc(MyDisplay);
		glutReshapeFunc(MyReshape);

		glutKeyboardFunc(MyKeyboard);
		glutSpecialFunc(MySpecial);

		glutMainLoop();
		return 0;
	}