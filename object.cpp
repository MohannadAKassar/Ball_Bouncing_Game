#include "object.h"
#include "world.h"

Object::Object(bool isStatic, float x, float y, const Color &color)
{
	_static = isStatic;
	_x = x;
	_y = y;
	_color = color;
	_visible = true;
	_collided = false;
}

void Object::BeforeUpdate(float dt)
{
	_collided = false;
}

void Object::Update(float dt)
{
	Move(GetVelocity());
}

bool Object::CheckCollide(Object *obj)
{
}

void Object::OnCollided()
{
	_collided = true;
}

bool Object::IsCollided() const
{
	return _collided;
}

void Object::SetVelocity(const Vector2 &velocity)
{
	_velocity = velocity;
}

Vector2 Object::GetVelocity() const
{
	return _velocity;
}

bool Object::IsStatic()
{
	return _static;
}

void Object::SetPosition(const Vector2 &pos)
{
	SetPosition(pos.x, pos.y);
}

void Object::SetPosition(float x, float y)
{
	_x = x;
	_y = y;
}

Vector2 Object::GetPosition() const
{
	return Vector2(_x, _y);
}

float Object::X() const
{
	return _x;
}

float Object::Y() const
{
	return _y;
}

Color Object::GetColor() const
{
	return _color;
}

void Object::Move(const Vector2 &pos)
{
	Move(pos.x, pos.y);
}

void Object::Move(float x, float y)
{
	_x += x;
	_y += y;
}

void Object::Destroy()
{
	world->Remove(this);
}

void Object::SetVisible(bool value)
{
	_visible = value;
}

bool Object::IsVisible()
{
	return _visible;
}

void Object::Draw()
{
	glColor3f(_color.r, _color.g, _color.b); 
}
