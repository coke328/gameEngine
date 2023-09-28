#pragma once
#define nanoSec 1000000000

namespace Math {
	float Clamp(float n, float min, float max);
	double SecToNanoSec(double sec);
	double NanoSecToSec(double nSec);
	double FpsToNanoSec(float fps);

}

