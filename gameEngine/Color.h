#pragma once
#include "math.h"

class Color {
private:

public:
	float r;
	float g;
	float b;

	Color();

	Color(float R, float G, float B);

	void setColor(float r, float g, float b);
};

