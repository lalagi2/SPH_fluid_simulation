#pragma once

#include "stdafx.h"
#include ""

cl_float4 operator+ (const cl_float4& lhs, const cl_float4& rhs)
{
	cl_float4 result;
	for (int i = 0; i < 4; ++i)
	{
		result.s[i] = lhs.s[i] + rhs.s[i];
	}

	return result;
}

cl_float4 operator+= (cl_float4& lhs, const cl_float4& rhs)
{
	for (int i = 0; i < 4; ++i)
	{
		lhs.s[i] = lhs.s[i] + rhs.s[i];
	}

	return lhs;
}

cl_float4 operator- (const cl_float4& lhs, const cl_float4& rhs)
{
	cl_float4 result;
	for (int i = 0; i < 4; ++i)
	{
		result.s[i] = lhs.s[i] - rhs.s[i];
	}

	return result;
}

cl_float4 operator-= (cl_float4& lhs, const cl_float4& rhs)
{
	for (int i = 0; i < 4; ++i)
	{
		lhs.s[i] = lhs.s[i] - rhs.s[i];
	}

	return lhs;
}

cl_float4 operator* (const cl_float4& lhs, const float& rhs)
{
	cl_float4 result;
	for (int i = 0; i < 4; ++i)
	{
		result.s[i] = lhs.s[i] * rhs;
	}

	return result;
}

int minimum(int a, int b) 
{
	if (a < b) 
	{
		return a;
	}
	return b;
}