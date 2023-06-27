#pragma once

struct Vector2{
public:
	float x;
	float y;
	Vector2();
	Vector2(float x, float y);
	
    static float Dot(const Vector2 &lhs, const Vector2 &rhs);
    static Vector2 Reflect(const Vector2 &inDir, const Vector2 &normal);
};
