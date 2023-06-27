#pragma once

#include <vector>
#include "object.h"

class World{
public:	
	~World();
	void Add(Object *obj);
	void Remove(Object *obj);
	const std::vector<Object*> GetObjects() const;
	
	void Update(float dt);
	
	void Draw();
private:
	std::vector<Object*> _objects;
};
