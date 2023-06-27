#include "block.h"
#include "world.h"

Block::Block(bool isStatic, const Vector2 &pos, const Vector2 &size, const Color &color): Object(isStatic, pos.x, pos.y, color), _size(size)
{
	
}	

Vector2 Block::Size() const
{
	return _size;
}
	
bool Block::CheckCollide(const Object &obj)
{
	
}

void Block::Update(float dt)
{
	Object::Update(dt);
}

void Block::Draw()
{
	if (IsVisible())
	{
		Object::Draw();
	    glRectf(X(), Y(), X() + Size().x, Y() + Size().y); 
	}
}

void Block::OnCollided()
{
	world->Remove(this);
}
