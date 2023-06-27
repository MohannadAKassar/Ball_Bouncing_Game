#pragma once

#include "block.h"

class CounterBlock: public Block{
public:
	CounterBlock(bool isStatic, const Vector2 &pos, const Vector2 &size, const Color &color = Color(1,1,1), int count = 0);
	
	void OnCollided();
	
	void Draw();
	
private:
	int _count;		
};
