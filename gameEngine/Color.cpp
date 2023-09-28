#include "Color.h"

Color::Color() {
	r = 255;
	g = 255;
	b = 255;
}

Color::Color(float R, float G, float B) {
	r = R;
	g = G;
	b = B;
}

void Color::setColor(float r, float g, float b) {
	r = Math::Clamp(r, 0, 255);
	g = Math::Clamp(g, 0, 255);
	b = Math::Clamp(b, 0, 255);
}