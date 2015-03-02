#include "stdafx.h"
#include <CL/cl.h>

#define PARTICLERADIUS 1
#define PARTICLERESOLUTION 7
#define PARTICLENUMBER 300

class Particle
{
public:
	cl_float4 position;
	cl_float4 velocity;
	cl_float4 acceleration;
};
