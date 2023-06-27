#pragma once

#include "object.h"

class Line: public Object{
public:
	Line(const Vector2 &from, const Vector2 &to, const Vector2 &normal);
	
	Vector2 From() const;
	Vector2 To() const;
	
	Vector2 Normal() const;
	
	bool CheckCollide(Object *obj);
	void Update(float dt);
	
	void Draw();
private:
	Vector2 _from;
	Vector2 _to;
	Vector2 _normal;
};
