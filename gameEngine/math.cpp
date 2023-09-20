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
