#pragma once

#include "block.h"

class Platform: public Block{
public:
	Platform(bool isStatic, const Vector2 &pos, const Vector2 &size, const Color &color = Color(1,1,1));
	
	void OnCollided();
};
