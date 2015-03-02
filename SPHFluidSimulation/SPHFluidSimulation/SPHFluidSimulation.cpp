// SPHFluidSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <CL/cl.h>

const int width = 600;
const int height = 600;

#define PARTICLERADIUS 300

void display()
{
	glClearColor(0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(300, 300, 0);
	glutSolidSphere(PARTICLERADIUS, 10, 10);
	glPopMatrix();

	// lala
	glutSwapBuffers();
}

void idle()
{
	glutPostRedisplay();
}

void onInitialization() {
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 599, 0, 599, PARTICLERADIUS, -PARTICLERADIUS);
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitContextVersion(3, 0);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("GPGPU 13. labor: Incompressible fluid simulation");


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);			
	glLoadIdentity();

	onInitialization();					

	glutDisplayFunc(display);
	glutIdleFunc(idle);

	// OpenCL processing
	//initSimulation();

	glutMainLoop();

	return(0);
}


