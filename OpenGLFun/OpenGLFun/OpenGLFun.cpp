#include <xstddef>
#include <windows.h>
#include "glut.h">

void initGL() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void drawPoints()
{
	glBegin(GL_POINTS);

	// Color of the vertex
	glColor3f(1.0f, 1.0f, 1.0f);

	// Drawing the points
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.4f, -0.1f);

	// OpenGL stop rendering
	glEnd();
}

void drawLines()
{
	glBegin(GL_LINES);

	glColor3f(1.0f, 1.0f, 1.0f);
	
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.4f, -0.1f);

	glEnd();
}

void update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//drawPoints();
	drawLines();
	glFlush();
}

int main()
{
	glutCreateWindow("GL Fun");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(500, 500);
	glutDisplayFunc(update);
	initGL();
	glutMainLoop();
	return 0;
}