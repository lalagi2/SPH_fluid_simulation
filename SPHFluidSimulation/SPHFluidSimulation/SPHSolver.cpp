#include "stdafx.h"
#include "SPHSolver.h"

void SPHSolver::addGravity(int dt)
{
	cl_float4 gravity = { 0.0f, _gravity, 0.0f, 0.0f };

	for (int n = 0; n < PARTICLENUMBER; n++)
	{
		particles[n]->velocity += gravity * ((float)dt / 1000.0f); // Y koordinátához gravitációt hozzáadjuk
		particles[n]->position -= particles[n]->velocity * ((float)dt / 1000.0f);

		if (particles[n]->position.s[1] <= 0.0f) // Bottom boundary condition
		{
			particles[n]->velocity.s[1] *= -1.0f;
		}

		if (particles[n]->position.s[0] <= 0.0f) // Left boundary condition
		{
			particles[n]->velocity.s[0] *= -1.0f;
		}

		if (particles[n]->position.s[0] <= (float)width) // Right boundary condition
		{
			particles[n]->velocity.s[0] *= -1.0f;
		}
	}
}