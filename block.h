#pragma once

#include "object.h"

class Block: public Object{
public:
	Block(bool isStatic, const Vector2 &pos, const Vector2 &size, const Color &color = Color(1,1,1));
	
	Vector2 Size() const;
	
	bool CheckCollide(const Object &obj);
	void OnCollided();
	void Update(float dt);
	
	void Draw();
private:
	Vector2 _size;
};
