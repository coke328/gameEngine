#include "math.h"

float Math::Clamp(float n, float min, float max) {
	if (n > max) {
		n = max;
	}
	else if (n < min) {
		n = min;
	}
	return n;
}
double Math::SecToNanoSec(double sec) {
	return sec * nanoSec;
}
double Math::NanoSecToSec(double nSec) {
	return nSec / nanoSec;
}
double Math::FpsToNanoSec(float fps) {
	return nanoSec / fps;
}

