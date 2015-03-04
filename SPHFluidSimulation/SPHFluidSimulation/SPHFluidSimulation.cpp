// SPHFluidSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <CL/cl.h>
#include <iostream>

#include "Particle.h"
#include "SPHSolver.h"
#include "Utils.h"

#define MAXDT 10

int Time = 0;

//SPHSolver solver;

void display()
{
	glClearColor(0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int n = 0; n < PARTICLENUMBER; n++)
	{
		cl_float4 position = particles[n]->position;

		glPushMatrix();
		glTranslatef(position.s[0], position.s[1], 0);
		glutSolidSphere(PARTICLERADIUS, PARTICLERESOLUTION, PARTICLERESOLUTION);
		glPopMatrix();
	}

	glutSwapBuffers();
}

void simulate(int lastTime, int time) 
{
	for (int ts = lastTime; ts <= time; ts += MAXDT) 
	{
		int te = minimum(time, ts + MAXDT);
		int dt = te - ts;

		//solver.addGravity(dt);
		//calcDensity();
	}
}

void idle()
{
	int lastTime = Time;
	Time = glutGet(GLUT_ELAPSED_TIME);

	simulate(lastTime, Time);

	glutPostRedisplay();
}

void onInitialization() 
{
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, 0, height, PARTICLERADIUS, -PARTICLERADIUS);

	cl_float positionStep = (cl_float)width / (cl_float)PARTICLENUMBER;
	cl_float xPosition = 0;
	for (int n = 0; n < PARTICLENUMBER; n++)
	{
		particles[n] = new Particle();
		particles[n]->position.s[0] = xPosition;
		particles[n]->position.s[1] = 500; // Y koordinátát beállítani
		particles[n]->position.s[2] = 0;
		particles[n]->position.s[3] = 0;

		particles[n]->velocity.s[0] = 0;
		particles[n]->velocity.s[1] = 0;
		particles[n]->velocity.s[2] = 0;
		particles[n]->velocity.s[3] = 0;

		xPosition += positionStep; // részecske sorban az új részecskét arrébb toljuk positionSteppel
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitContextVersion(3, 0);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("Smoothed-particle hydrodynamics");

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


