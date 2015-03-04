#include "stdafx.h"

cl_float4 operator+ (const cl_float4& lhs, const cl_float4& rhs)
{
	cl_float4 result;
	for (int i = 0; i < 4; ++i)
	{
		result.s[i] = lhs.s[i] + rhs.s[i];
	}

	return result;
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

cl_float4 operator* (const cl_float4& lhs, const float& rhs)
{
	cl_float4 result;
	for (int i = 0; i < 4; ++i)
	{
		result.s[i] = lhs.s[i] * rhs;
	}

	return result;
}