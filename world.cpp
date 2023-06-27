#include "world.h"

World::~World()
{
	for(int i=0,c=_objects.size();i<c;i++)
	{
		Object* obj = _objects[i];
		delete obj;
	}
}

void World::Add(Object *obj)
{
	_objects.push_back(obj);
	obj->world = this;
}

const std::vector<Object*> World::GetObjects() const
{
	return _objects;
}

void World::Update(float dt)
{
	for(int i=0,c=_objects.size();i<c;i++)
	{
		Object* obj = _objects[i];
		if (!obj->IsStatic())
		{
			obj->BeforeUpdate(dt);
			for(int j=0,cj=_objects.size();j<cj;j++)
			{
				Object* o = _objects[j];
				obj->CheckCollide(o);
			}
				
			obj->Update(dt);
		}
	}
}

void World::Remove(Object *obj)
{
	for(int i=0,c=_objects.size();i<c;i++)
	{
		if (obj == _objects[i])
			_objects.erase( _objects.begin() + i );
	}
}

void World::Draw()
{
	for(int i=0,c=_objects.size();i<c;i++)
	{
		Object *obj = _objects[i];
		if (obj->IsVisible())
			obj->Draw();
	}
}
