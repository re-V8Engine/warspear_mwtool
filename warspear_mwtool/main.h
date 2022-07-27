#pragma once


struct Vector2D
{
	float x, y;
	Vector2D() { x = y = 0.0f; }
	Vector2D(float _x, float _y) { x = _x; y = _y; }
};

struct ARGBColor
{
	int a, r, g, b;
	ARGBColor() { a = r = g = b = 0; }
	ARGBColor(int _a, int _r, int _g, int _b) { a = _a; r = _r; g = _g; b = _b; }

};
