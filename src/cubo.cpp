#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

float angulo = -10;

void ocioso() {
	if(angulo > 10) {
		angulo = -10;
	}
	angulo += 0.001;
	glutPostRedisplay();
}

void inicio() {
	// window background color
	glClearColor(0.1,0.1,0.1,1);
}

void desenha() {
	float x = 0.3, y = 0.3;
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-x,x,-y,y,1, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(3,     3,     angulo,
			  0,     0,     0,
			  0,     0,     1);

	
	// Points
	GLfloat A[3] = {0,0,0};
	GLfloat B[3] = {1,0,0};
	GLfloat C[3] = {0,1,0};
	GLfloat D[3] = {0,0,1};
	GLfloat E[3] = {1,1,0};
	GLfloat F[3] = {1,0,1};
	GLfloat G[3] = {0,1,1};
	GLfloat H[3] = {1,1,1};

	
	// Face 1 - A B E C
	glBegin(GL_POLYGON);
		// A point
		glColor3f (A[0], A[1], A[2]);
		glVertex3f(A[0], A[1], A[2]);
		
		// B point
		glColor3f (B[0], B[1], B[2]);
		glVertex3f(B[0], B[1], B[2]);
		
		// E point
		glColor3f (E[0], E[1], E[2]);
		glVertex3f(E[0], E[1], E[2]);
		
		// C point
		glColor3f (C[0], C[1], C[2]);
		glVertex3f(C[0], C[1], C[2]);
	glEnd();
	
	// Face 2 - A D F B
	glBegin(GL_POLYGON);
		// A point
		glColor3f (A[0], A[1], A[2]);
		glVertex3f(A[0], A[1], A[2]);
		
		// D point
		glColor3f (D[0], D[1], D[2]);
		glVertex3f(D[0], D[1], D[2]);
		
		// F point
		glColor3f (F[0], F[1], F[2]);
		glVertex3f(F[0], F[1], F[2]);
		
		// B point
		glColor3f (B[0], B[1], B[2]);
		glVertex3f(B[0], B[1], B[2]);
	glEnd();

	// Face 3 - C G D A
	glBegin(GL_POLYGON);
		// C point
		glColor3f (C[0], C[1], C[2]);
		glVertex3f(C[0], C[1], C[2]);
		
		// G point
		glColor3f (G[0], G[1], G[2]);
		glVertex3f(G[0], G[1], G[2]);
		
		// D point
		glColor3f (D[0], D[1], D[2]);
		glVertex3f(D[0], D[1], D[2]);
		
		// A point
		glColor3f (A[0], A[1], A[2]);
		glVertex3f(A[0], A[1], A[2]);
	glEnd();
	
	// Face 4 - B F H E
	glBegin(GL_POLYGON);
		// B point
		glColor3f (B[0], B[1], B[2]);
		glVertex3f(B[0], B[1], B[2]);
		
		// F point
		glColor3f (F[0], F[1], F[2]);
		glVertex3f(F[0], F[1], F[2]);
		
		// H point
		glColor3f (H[0], H[1], H[2]);
		glVertex3f(H[0], H[1], H[2]);
		
		// E point
		glColor3f (E[0], E[1], E[2]);
		glVertex3f(E[0], E[1], E[2]);
	glEnd();
	
	// Face 5 - E H G C
	glBegin(GL_POLYGON);
		// E point
		glColor3f (E[0], E[1], E[2]);
		glVertex3f(E[0], E[1], E[2]);
		
		// H point
		glColor3f (H[0], H[1], H[2]);
		glVertex3f(H[0], H[1], H[2]);
		
		// G point
		glColor3f (G[0], G[1], G[2]);
		glVertex3f(G[0], G[1], G[2]);
		
		// C point
		glColor3f (C[0], C[1], C[2]);
		glVertex3f(C[0], C[1], C[2]);
	glEnd();
	
	// Face 6 - D F H G
	glBegin(GL_POLYGON);
		// D point
		glColor3f (D[0], D[1], D[2]);
		glVertex3f(D[0], D[1], D[2]);
		
		// F point
		glColor3f (F[0], F[1], F[2]);
		glVertex3f(F[0], F[1], F[2]);
		
		// H point
		glColor3f (H[0], H[1], H[2]);
		glVertex3f(H[0], H[1], H[2]);
		
		// G point
		glColor3f (G[0], G[1], G[2]);
		glVertex3f(G[0], G[1], G[2]);
	glEnd();
	
	ocioso();
	glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cubo");

	inicio();
	glutDisplayFunc(desenha);
	glutMainLoop();
    return 0;
}