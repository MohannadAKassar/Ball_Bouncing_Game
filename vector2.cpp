#include "vector2.h"

Vector2::Vector2()
{
}
Vector2::Vector2(float x, float y): x(x),y(y){
}

float Vector2::Dot(const Vector2 &lhs, const Vector2 &rhs) 
{
	return lhs.x * rhs.x + lhs.y * rhs.y; 
}

Vector2 Vector2::Reflect(const Vector2 &inDir, const Vector2 &normal)
{
    float factor = -2 * Dot(normal, inDir);
    return Vector2(factor * normal.x + inDir.x, factor * normal.y + inDir.y);
}
