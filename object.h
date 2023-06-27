#pragma once

#include "tools.h"
#include "vector2.h"

class World;

class Object{
public:
	Object(bool isStatic, float x = 0, float y = 0, const Color &color = Color(1,1,1));
	void BeforeUpdate(float dt);
	virtual void Update(float dt);
	virtual bool CheckCollide(Object *obj);
	virtual void OnCollided();
	bool IsCollided() const;
	
	void SetVelocity(const Vector2 &velocity);
	Vector2 GetVelocity() const;
	
	bool IsStatic();
	
	Vector2 GetPosition() const;
	float X() const;
	float Y() const;
	
	Color GetColor() const;
	
	void SetVisible(bool value);
	bool IsVisible();
	
	virtual void Draw();
	
	void SetPosition(const Vector2 &pos);
	void SetPosition(float x, float y);
	void Move(const Vector2 &pos);
	void Move(float x, float y);
	
	void Destroy();

	World *world;
private:
	float _x;
	float _y;
	bool _static;
	Vector2 _velocity;
	Color _color;
	bool _visible;
	bool _collided;
};
