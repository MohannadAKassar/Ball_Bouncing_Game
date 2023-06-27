#pragma once

#include "object.h"
#include "line.h"

class Circle: public Object{
public:
	Circle(bool isStatic, float x, float y, float radius, const Color &color = Color(1,1,1));
	
	bool CheckCollide(Object *obj);
	bool CheckLineCollide(const Line &line);

	void Update(float dt);
	void Draw();
private:
	float _radius;
};
