#include <xstddef>
#include <windows.h>
#include "glut.h">
#include <cstdio>

GLuint texture;
#pragma warning(disable: 4996)

bool loadTexture(const char* filename)
{
	unsigned char header[54];
	unsigned char* data;
	int dataPos;
	int width;
	int height;
	int imageSize;

	FILE* file = fopen(filename, "rb");
	if (!file) return false;
	if (fread(header, 1, 54, file) != 54) return false;
	if (header[0] != 'B' || header[1] != 'M') return false;

	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	if (imageSize == 0) imageSize = width * height * 3;
	if (dataPos == 0) dataPos = 54;

	data = new unsigned char[imageSize];
	fread(data, 1, imageSize, file);
	fclose(file);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	return true;
}


void initGL() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
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
void drawSolidTriangle()
{
	glBegin(GL_TRIANGLES);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.4f, -0.1f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.4f, -0.1f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.1f, 0.4f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.7f, 0.4f);

	glEnd();
}

void drawQuad()
{
	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, -0.4f);
	glVertex2f(0.4f, -0.4f);
	glVertex2f(0.4f, -0.1f);
	//test
	glEnd();
}

void drawTexture()
{
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0); glVertex2d(0.0, 0.0);
	glTexCoord2d(1.0, 0.0); glVertex2d(0.5, 0.0);
	glTexCoord2d(1.0, 1.0); glVertex2d(0.5, 0.5);
	glTexCoord2d(0.0, 1.0); glVertex2d(0.0, 0.5);

	glEnd();
}

void update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//	drawPoints();
	//	drawLines();
	//	drawSolidTriangle();
	//drawQuad();
	drawTexture();
	glFlush();
}

int main()
{
	glutCreateWindow("GL Fun");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(500, 500);
	glutDisplayFunc(update);
	initGL();
	//loadTexture("*/estesi.bmp"); 
	glutMainLoop();
	return 0;
}
