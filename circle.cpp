#include "circle.h"
#include "line.h"
#include "block.h"

Circle::Circle(bool isStatic, float x, float y, float radius, const Color &color): Object(isStatic, x, y, color), _radius(radius)
{
	
}


bool Circle::CheckCollide(Object *obj)
{
	bool collide = false;
	Line* line = dynamic_cast<Line*>(obj);
	if (line)
	{
		collide = CheckLineCollide(*line);
		if (collide)
			line->OnCollided();
	}
	else
	{
		Block* block = dynamic_cast<Block*>(obj);
		if (block)
		{
			collide |= CheckLineCollide(Line(block->GetPosition(), Vector2(block->X()+block->Size().x, block->Y()), Vector2(0,-1)));
			collide |= CheckLineCollide(Line(Vector2(block->X(), block->Y()+ block->Size().y), 
						 Vector2(block->X()+block->Size().x, block->Y()+ block->Size().y), Vector2(0,1)));
			collide |= CheckLineCollide(Line(Vector2(block->X(), block->Y()), 
						 Vector2(block->X(), block->Y()+ block->Size().y), Vector2(-1,0)));
			collide |= CheckLineCollide(Line(Vector2(block->X()+block->Size().x, block->Y()), 
						 Vector2(block->X()+block->Size().x, block->Y()+ block->Size().y), Vector2(1,0)));
						 
			if (collide)
				block->OnCollided();
		}
	}
	return collide;
}

bool Circle::CheckLineCollide(const Line &line)
{
	float distance = Tools::ShortestDistance(line.From().x, line.From().y, line.To().x, line.To().y, X(), Y());
	if (distance <= _radius)
	{
		float f1 = Vector2::Dot(Vector2(0,1), Vector2(0,-1));
		float f2 = Vector2::Dot(Vector2(1,0), Vector2(0,1));
		
		float f = Vector2::Dot(GetVelocity(), line.Normal());
		if (f<0)
		{
			Vector2 v = GetVelocity();
			Vector2 direction = Vector2::Reflect(GetVelocity(), line.Normal());
			SetVelocity(direction);
			return true;
		}
	}
	return false;
}

void Circle::Update(float dt)
{
	Object::Update(dt);
}

void Circle::Draw()
{
	if (IsVisible())
	{
		Tools::DrawCircle(X(), Y(), _radius, GetColor());
	}
}
