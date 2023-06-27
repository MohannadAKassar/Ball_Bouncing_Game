#include "line.h"

Line::Line(const Vector2 &from, const Vector2 &to, const Vector2 &normal): Object(true), _from(from), _to(to), _normal(normal)
{
	
}

Vector2 Line::From() const
{
	return _from;
}

Vector2 Line::To() const
{
	return _to;
}

Vector2 Line::Normal() const
{
	return _normal;
}

bool Line::CheckCollide(Object *obj)
{
	Object::CheckCollide(obj);
}

void Line::Update(float dt)
{
	Object::Update(dt);
}

void Line::Draw()
{
	if (IsVisible())
	{
		Object::Draw();
		glBegin(GL_LINES);
		glVertex2f(_from.x, _from.y);
		glVertex2f(_to.x, _to.y);
		glEnd();
	}
}
