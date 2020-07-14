#include <glut.h>
GLboolean IsSphere = true;
GLboolean IsSmall = true;
GLboolean IsStyle = true;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.5, 0.5);
	if ((IsSphere) && (IsSmall) && (IsStyle))glutWireSphere(0.5, 30, 30);
	else if ((IsSphere) && (!IsSmall) && (IsStyle)) glutWireSphere(0.7, 30, 30);
	else if ((IsSphere) && (!IsSmall) && (!IsStyle)) glutSolidSphere(0.7,30,30);
	else if ((IsSphere) && (IsSmall) && (!IsStyle)) glutSolidSphere(0.3, 30, 30);
	else if ((!IsSphere) && (IsSmall) && (IsStyle)) glutWireTorus(0.1, 0.3, 40, 20);
	else if ((!IsSphere) && (IsSmall) && (!IsStyle)) glutSolidTorus(0.1, 0.3, 40, 20);
	else if ((!IsSphere) && (!IsSmall) && (!IsStyle)) glutSolidTorus(0.1, 0.7, 40, 20);
	else if ((!IsSphere) && (!IsSmall) && (IsStyle)) glutWireTorus(0.1, 0.7, 40, 20);

	glFlush();
}
void MyMainMenu(int entryID) {
	if (entryID == 1)   IsSphere = true;
	else if (entryID == 2)   IsSphere = false;
	else if (entryID == 3)   exit(0);
	glutPostRedisplay();
}
void MySizeMenu(int entryID) {
	if (entryID == 1)   IsSmall = true;
	else if (entryID == 2)  IsSmall = false;
	glutPostRedisplay();
}
void MyStyleMenu(int entryID) {
	if (entryID == 1) IsStyle = true; //style�� 1�̸� wire, 2�� solid
	else if (entryID == 2) IsStyle = false;
	glutPostRedisplay();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	GLint MySizeID = glutCreateMenu(MySizeMenu);
	glutAddMenuEntry("Small", 1);
	glutAddMenuEntry("Large", 2);

	GLint MyStyleID = glutCreateMenu(MyStyleMenu);
	glutAddMenuEntry("Wire", 1);
	glutAddMenuEntry("Solid", 2);


	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);
	glutAddSubMenu("Size", MySizeID);
	glutAddSubMenu("Style", MyStyleID);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Menu Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}