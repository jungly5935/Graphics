#include <glut.h>
#include <math.h> 
#define Pi 3.1415 
#define WIN_WIDTH 1000  // window 4:3
#define WIN_HEIGHT 750

unsigned char gFace = 'u';   // u:usual  a:angry   s:smiling
GLfloat gY = 0.0;  // jump
GLfloat gX = 0.0;  // moving-X

GLfloat gBlueleg = 0.0;//ȸ������ l,k
GLfloat gBlackleg = 0.0; //f,d
GLfloat gRedforearm = 0.0; // p, o (���� 90 ~ -90)
GLfloat gBlackforearm = 0.0; // e,r
GLfloat gRedupperarm = 0.0; // p, o (���� 90 ~ -90)��
GLfloat gBlackupperarm = 0.0; // e,r
GLfloat gRedarmlength = 1.0; //0 9 
GLfloat gShear = 0.0, gShearleg = 0.0;

GLfloat gBearShear = 0.0, gBearShearleg = 0.0;
GLfloat gBearforearm = 0.0; //������ 
GLfloat gBeararm = 0.0; //��������
GLfloat gBearforeleg = 0.0; //���ʴٸ�
GLfloat gBearleg = 0.0; //�����ʴٸ�


void YourBackground();
void YourMat();
void YourFace();
void YourEyeMouth();
void YourBody();
void YourBear();

void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	YourBackground();
	YourMat();
	
	/* //�ݻ�
	glRotatef(-45, 0, 0, 1);
	glScalef(-1, 1, 1);
	glRotatef(45, 0, 0, 1);

	glTranslatef(2, 0, 0);
	*/
	glPushMatrix();
	glTranslatef(gX, gY, 0);

	GLfloat Shear_arr[4][4] = {
		{1,0,0,0},
		{gShear,1,0,0},
		{0,0,1,0},
		{0,0,0,1},

	};
	glTranslatef(0, -1, 0); //�߳����� 3
	glMultMatrixf((float*)Shear_arr); 
	//���縷�ù��� �߳� -1 ��, �߳����� 2
	glTranslatef(0, 1, 0); //�߳����� 1

	//glScalef(1, -1, 1); // x�࿡ ���� �ݻ�

	YourFace();
	YourEyeMouth();
	YourBody(); 	
	glPopMatrix();

	//---------------------������(Something)--------------
	glPushMatrix();
	glTranslatef(-2.5, -1.5, 0); //���ʾƷ��� ��ġ �̵�
	GLfloat BearShear_arr[4][4] = { //��ü shear
		{1,0,0,0},
		{gBearShear,1,0,0},
		{0,0,1,0},
		{0,0,0,1},
	
	};
	
	glTranslatef(0, -1.2, 0); //�߳����� 3
	glMultMatrixf((float*)BearShear_arr);
	// �߳����� 2
	glTranslatef(0, 1.2, 0); //�߳����� 1

	YourBear();
	glPopMatrix();

	glutSwapBuffers();

} // MyDisplay

void YourBear() {
	GLfloat Size[2], Angle;

	/////////��ݺν���///////////////
	glColor3f(0.4353, 0.3098, 0.1569);
	glBegin(GL_POLYGON); //������ ��
	for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.4 * cos(Angle), 0.4 * sin(Angle), 0.0);
	glEnd();


	glPushMatrix();
	glTranslatef(-0.4, 0.2, 0);
	glBegin(GL_POLYGON); //������ ���ʱ�
	for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.15 * cos(Angle), 0.15 * sin(Angle), 0.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.4, 0.2, 0);
	glBegin(GL_POLYGON); //������ �����ʱ�
	for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.15 * cos(Angle), 0.15 * sin(Angle), 0.0);
	glEnd();
	glPopMatrix();

	/////////��ݺ� ��///////////////


	///////////////////////�Ϲݺ� ���� ////////////////
	glPushMatrix();
	glTranslatef(0, -0.6, 0);
	glBegin(GL_POLYGON); //������ ����
	for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.5 * cos(Angle), 0.5 * sin(Angle), 0.0);
	glEnd();
	glPopMatrix();
	
	glLineWidth(20);
	glBegin(GL_LINES); // ������
	glVertex3f(-0.4, -0.4, 0);
	glVertex3f(-0.6, -0.5, 0);
	glEnd();

	glBegin(GL_LINES); //��������
	glVertex3f(0.4, -0.4, 0);
	glVertex3f(0.6, -0.5, 0);
	glEnd();

	glPushMatrix(); //�δٸ� ����
	GLfloat BearShear_arr[4][4] = { //�δٸ��� shear
	{1,0,0,0},
	{gBearShearleg,1,0,0},
	{0,0,1,0},
	{0,0,0,1},

	};
	glTranslatef(-0.3,-0.9, 0); //�߳����� 3
	glMultMatrixf((float*)BearShear_arr);
	// �߳����� 2
	glTranslatef(0.3, 0.9, 0); //�߳����� 1

	glBegin(GL_LINES); //���ʴٸ�
	glVertex3f(-0.3, -0.9, 0);
	glVertex3f(-0.3, -1.2, 0);
	glEnd();
	glBegin(GL_LINES); //�����ʴٸ�
	glVertex3f(0.3, -0.9, 0);
	glVertex3f(0.3, -1.2, 0);
	glEnd();
	glPopMatrix(); //�� �ٸ� ��



	//////////////////�Ϲݺ� ��////////////////////


	glPushMatrix();
	glColor3f(0.9608, 0.7608, 0.6627);
	glTranslatef(0, -0.1, 0);
	glBegin(GL_POLYGON); //������ ��
	for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.15 * cos(Angle), 0.15 * sin(Angle), 0.0);
	glEnd();
	glPopMatrix();


	glColor3f(0, 0, 0);
	glPushMatrix();
	glEnable(GL_POINT_SMOOTH);
	glPointSize(5);
	glBegin(GL_POINTS); //������ ��
	glVertex3f(-0.1, 0.05, 0);
	glVertex3f(0.1, 0.05, 0);
	glEnd();

	glPointSize(10);
	glBegin(GL_POINTS); //������  ��
	
	glVertex3f(0, -0.1, 0);
	glEnd();

	glLineWidth(1);
	glPopMatrix();





}
void YourBackground() {

	glColor3f(0, 1, 1); // sky 

	glBegin(GL_POLYGON);
	glVertex3f(-4, 0, -4);
	glVertex3f(4, 0, -4);
	glVertex3f(4, 3, -4);
	glVertex3f(-4, 3, -4);
	glEnd();

	glColor3f(0, 1, 0); // green 

	glBegin(GL_POLYGON);
	glVertex3f(-4, -3, -4);
	glVertex3f(4, -3, -4);
	glVertex3f(4, 0, -4);
	glVertex3f(-4, 0, -4);
	glEnd();

}

void YourMat() {

	glColor3f(0xE4 / 255.0, 0xBE / 255.0, 0xFE / 255.0); // �������	
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, -1.3, 0);
	glVertex3f(1.2, -1.3, 0);
	glVertex3f(1.5, -0.8, 0);
	glVertex3f(-1.2, -0.8, 0);
	glEnd();

} // YourMat


void YourFace() {
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // �챸��
	
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();
} // YourFace 


void YourEyeMouth() {

	if (gFace == 'a') {  // angry

		glColor3f(0, 0, 0); // black

		glBegin(GL_LINES);
		glVertex3f(-0.3, 1.2, 0.0); // eye
		glVertex3f(-0.1, 1.0, 0.0);
		glVertex3f(0.1, 1.0, 0.0); // eye
		glVertex3f(0.3, 1.2, 0.0);
		glEnd();

		glBegin(GL_LINE_LOOP); // mouth
		glVertex3f(-0.1, 0.9, 0.0);
		glVertex3f(0.1, 0.9, 0.0);
		glVertex3f(0.1, 0.8, 0.0);
		glVertex3f(-0.1, 0.8, 0.0);
		glEnd();
	}
	else if (gFace == 's') { // smiling

		glColor3f(0, 0, 0); // black

		glBegin(GL_LINE_STRIP); // eye
		glVertex3f(-0.3, 1.1, 0.0);
		glVertex3f(-0.2, 1.15, 0.0);
		glVertex3f(-0.1, 1.1, 0.0);
		glEnd();
		glBegin(GL_LINE_STRIP);	// eye
		glVertex3f(0.1, 1.1, 0.0);
		glVertex3f(0.2, 1.15, 0.0);
		glVertex3f(0.3, 1.1, 0.0);
		glEnd();

		glColor3f(1, 0, 0); // red

		glBegin(GL_LINE_LOOP); // mouth
		glVertex3f(-0.1, 0.9, 0.0);
		glVertex3f(0.1, 0.9, 0.0);
		glVertex3f(0, 0.8, 0.0);
		glEnd();
	}
	else if (gFace == 'u') { // usual

		glColor3f(0, 0, 0); // black

		glBegin(GL_LINES);
		glVertex3f(-0.3, 1.1, 0.0); // eye
		glVertex3f(-0.1, 1.1, 0.0);
		glVertex3f(0.1, 1.1, 0.0); // eye
		glVertex3f(0.3, 1.1, 0.0);
		glVertex3f(-0.1, 0.9, 0.0); // mouth
		glVertex3f(0.1, 0.9, 0.0);
		glEnd();
	}

} // YourEyeMouth



void YourBody() {


	glColor3f(0, 0, 0); // black neck

	glBegin(GL_LINES);
	glVertex3f(0, 0.5, 0.0);
	glVertex3f(0, 0.3, 0.0);
	glEnd();

	glColor3f(0.5, 0.5, 0.5); // gray spine

	glBegin(GL_POLYGON);
	glVertex3f(-0.05, -0.3, 0.0);
	glVertex3f(0.05, -0.3, 0.0);
	glVertex3f(0.05, 0.3, 0.0);
	glVertex3f(-0.05, 0.3, 0.0);
	glEnd();


	glLineWidth(3); // line 


	//red �� ��ü ���� 4�� �߰�
	glPushMatrix();
	glTranslatef(0.05, 0.3, 0.0);
	glRotatef(gRedupperarm, 0, 0, 1);
	glScalef(gRedarmlength, gRedarmlength, 1);
	glTranslatef(-0.05, -0.3, 0.0);
 
		glColor3f(1, 0, 0); // red arm
		glBegin(GL_LINES); // upper
			glVertex3f(0.05, 0.3, 0.0);
			glVertex3f(0.25, 0.1, 0.0);
			glEnd();

			glPushMatrix();
			glTranslatef(0.25, 0.1, 0);
			glRotatef(gRedforearm, 0, 0, 1);
			glTranslatef(-0.25, -0.1, 0);
		glBegin(GL_LINES); // lower	
		glVertex3f(0.25, 0.1, 0.0);
		glVertex3f(0.5, -0.2, 0.0);

		glEnd();
		glPopMatrix();
	glPopMatrix();

	//black �� ��ü ���� (4���߰�)
	glPushMatrix();
	glTranslatef(-0.05, 0.3, 0.0);
	glRotatef(gBlackupperarm, 0, 0, 1);
	glTranslatef(0.05, -0.3, 0.0);



		glColor3f(0, 0, 0); // black arm

		glBegin(GL_LINES); //upper
		glVertex3f(-0.05, 0.3, 0.0);
		glVertex3f(-0.25, 0.1, 0.0);
		glEnd();

		glPushMatrix();
		glTranslatef(-0.25, 0.1, 0);
		glRotatef(gBlackforearm, 0, 0, 1);
		glTranslatef(0.25, -0.1, 0);
		glBegin(GL_LINES); //lower
		glVertex3f(-0.25, 0.1, 0.0);
		glVertex3f(-0.5, -0.2, 0.0);
		glEnd();
		glPopMatrix();
	glPopMatrix(); //black ��ü �� 


	glPushMatrix(); //�ٸ� �� �� ����
	GLfloat Shearleg_arr[4][4] = { //�Լ� �ȿ��ִ°Ŷ� �̸� ���Ƶ� �������
	{1,0,0,0},
	{gShearleg,1,0,0},
	{0,0,1,0},
	{0,0,0,1},

	};
	glTranslatef(0, -0.3, 0); 
	glMultMatrixf((float*)Shearleg_arr);
	glTranslatef(0, 0.3, 0);

	glColor3f(0, 0, 1); // blue leg
	glPushMatrix();
	glTranslatef(0.05, -0.3, 0); // (3) �ٸ��� ���� ����
	glRotatef(gBlueleg, 0, 0, 1); //(2)z�� ���� gBlueleg������ŭ ȸ��
	glTranslatef(-0.05, 0.3, 0); //(1) �ٸ��� �������� �����ϵ��� �̵�
	glBegin(GL_LINES);
	glVertex3f(0.05, -0.3, 0.0);
	glVertex3f(0.3, -1.0, 0.0);
	glEnd();
	glPopMatrix();

	glColor3f(0, 0, 0); // black leg

	glTranslatef(-0.05, -0.3, 0);
	glRotatef(gBlackleg, 0, 0, 1);
	glTranslatef(0.05, 0.3, 0);
	glPushMatrix(); //push��ġ translatef ���������ϴ°žƴѰ�?�������?
	glBegin(GL_LINES);
	glVertex3f(-0.05, -0.3, 0.0);
	glVertex3f(-0.3, -1.0, 0.0);
	glEnd();
	glPopMatrix();
	glPopMatrix(); // �� �ٸ� ��


	glLineWidth(1);  // line

	

} // YourBody

void MyKeyboard(unsigned char key, int x, int y) {

	switch (key) {

	case 'Q':
	case 'q':	exit(0);  break;

	case 'a':
	case 's':
	case 'u':   gFace = key;   break;	 // face

	case 'l': gBlueleg += 10; break;
	case 'k': gBlueleg -= 10; break;
	case 'd': gBlackleg += 10; break;
	case 'f': gBlackleg -= 10; break;

	case 'p': if(gRedforearm <90)gRedforearm += 3; break;
	case 'o': if(gRedforearm >-90) gRedforearm -= 3; break;

	case 'r': if (gRedforearm < 90)gBlackforearm += 10; break;
	case 'e': if (gRedforearm > -90)gBlackforearm -= 10; break;

	case 'P': if (gRedupperarm < 90)gRedupperarm += 3; break;
	case 'O': if (gRedupperarm > -90) gRedupperarm -= 3; break;

	case 'R': if(gRedupperarm < 90) gBlackupperarm += 10; break;
	case 'E': if(gRedupperarm > -90) gBlackupperarm -= 10; break;

		
	case '0':  gRedarmlength *= 1.1; break; //���� 0�̶� 9��
	case '9': if(gRedarmlength > 1)  gRedarmlength /= 1.1; break;


	}

	glutPostRedisplay();

} // MyKeyboard

void MySpecial(int key, int x, int y) {

	switch (key) {

	case GLUT_KEY_UP: 	gY = 1;  
		gRedforearm = 30; gBlackforearm = -30; gBlueleg = -19.5; gBlackleg = 19.5;
		break;

	case GLUT_KEY_DOWN: gY = 0;	 
		gRedforearm = 0; gBlackforearm = 0; gBlueleg= 0, gBlackleg = 0;
		break;

	case GLUT_KEY_LEFT:
		if (gY == 0) {
			gX -= 0.1;
			if (gX < -1.5 || gX >1.5) gFace = 'a'; else gFace = 'u'; break;
		}
	case GLUT_KEY_RIGHT:
		if (gY == 0) {
			gX += 0.1;
			if (gX < -1.5 || gX >1.5) gFace = 'a'; else gFace = 'u'; break;
			break;
		}


	case GLUT_KEY_F1: gShear = -0.5; gFace = 's'; //���� ����
		gRedupperarm = 48; gBlackupperarm = -48; 
		gBearShear = -0.5;
		break;
	case GLUT_KEY_F2: gShear = 0.0; gFace = 'u'; 
		gRedupperarm = 0; gBlackupperarm = -0;  
		gBearShear = 0.0;
		break;

	case GLUT_KEY_F3: gShear = 0.5; gFace = 's'; 
		gRedupperarm = 48; gBlackupperarm = -48; 
		gBearShear = 0.5;
		break;


	case GLUT_KEY_F4: gShearleg = 0.5; gFace = 's'; //�ٸ� ����
		gRedupperarm = 48; gBlackupperarm = -48; 
		gBearShearleg = 0.5;
		break;
	case GLUT_KEY_F5: gShearleg = 0.0; gFace = 'u';
		gRedupperarm = 0; gBlackupperarm = 0;  
		gBearShearleg = 0; 
		break;

	case GLUT_KEY_F6: gShearleg = -0.5; gFace = 's';
		gRedupperarm = 48; gBlackupperarm = -48; 
		gBearShearleg = -0.5; 
		break;

	}//switch


	glutPostRedisplay();

} // MySpecial



void MyReshape(int NewWidth, int NewHeight) {

	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)WIN_WIDTH;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)WIN_HEIGHT;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0 * WidthFactor, 4.0 * WidthFactor, -3.0 * HeightFactor, 3.0 * HeightFactor, -4.0, 4.0);

} // MyReshape


void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// menu callback 

} // MyInit


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutInitWindowPosition(150, 0);
	glutCreateWindow("Maximus");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);

	glutMainLoop();
	return 0;
}
