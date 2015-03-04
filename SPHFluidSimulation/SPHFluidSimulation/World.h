#pragma once

#include "stdafx.h"
#include "Particle.h"

#define PARTICLENUMBER 300

const int width = 600; // Window width
const int height = 600; // Window height
const float _gravity = 50.0f;

Particle* particles[PARTICLENUMBER];
//cl_mem particles;