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
#include "Utils.h"

#define MAXDT 10

const int width = 600;
const int height = 600;

int Time = 0;

Particle* particles[PARTICLENUMBER];
//cl_mem particles;

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

void addGravity(int dt)
{
	for (int n = 0; n < PARTICLENUMBER; n++)
	{
		particles[n]->velocity.s[1] += gravity * (float)dt / 1000.0f; // Y koordin�t�hoz gravit�ci�t hozz�adjuk
		particles[n]->position.s[1] -= particles[n]->velocity.s[1] * (float)dt / 1000.0f;

		if (particles[n]->position.s[1] <= 0.0f) // Bottom boundary condition
		{
			particles[n]->velocity.s[1] *= -1.0f;
		}

		// TODO: Implement all boundary condition
	}
}

void simulate(int lastTime, int time) 
{
	for (int ts = lastTime; ts <= time; ts += MAXDT) 
	{
		int te = minimum(time, ts + MAXDT);
		int dt = te - ts;

		addGravity(dt);
	}
}

void idle()
{
	int lastTime = Time;
	Time = glutGet(GLUT_ELAPSED_TIME);

	simulate(lastTime, Time);

	glutPostRedisplay();
}

void onInitialization() {
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, 0, height, PARTICLERADIUS, -PARTICLERADIUS);

	cl_float positionStep = (cl_float)width / (cl_float)PARTICLENUMBER;
	cl_float xPosition = 0;
	for (int n = 0; n < PARTICLENUMBER; n++)
	{
		particles[n] = new Particle();
		particles[n]->position.s[0] = xPosition;
		particles[n]->position.s[1] = 500; // Y koordin�t�t be�ll�tani
		particles[n]->position.s[2] = 0;
		particles[n]->position.s[3] = 0;

		particles[n]->velocity.s[0] = 0;
		particles[n]->velocity.s[1] = 0;
		particles[n]->velocity.s[2] = 0;
		particles[n]->velocity.s[3] = 0;

		xPosition += positionStep; // r�szecske sorban az �j r�szecsk�t arr�bb toljuk positionSteppel
	}
}

int main(int argc, char* argv[]){
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


