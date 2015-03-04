#pragma once

#include "stdafx.h"
#include <CL/cl.h>

#define PARTICLERADIUS 1
#define PARTICLERESOLUTION 5

class Particle
{
public:
	cl_float4 position;
	cl_float4 velocity;
	cl_float4 acceleration;
	cl_float particleMass;

	Particle()
	{
		particleMass = 1.0f;
	}
};
