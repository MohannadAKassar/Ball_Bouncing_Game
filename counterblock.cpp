#include "counterblock.h"
#include <string> 
#include <vector> 

CounterBlock::CounterBlock(bool isStatic, const Vector2 &pos, const Vector2 &size, const Color &color, int count): Block(isStatic, pos, size, color), _count(count)
{
	
}	

void CounterBlock::OnCollided()
{
	_count--;
	if (_count <= 0)
		Block::OnCollided();
}

void CounterBlock::Draw()
{
	Block::Draw();
	glColor3f(1, 1, 1); 
	char str[100];
	sprintf(str, "%d", _count);
	std::string s = str;
	
    unsigned char string[s.length() + 1];
    std::copy(s.data(), s.data() + s.length() + 1, string);

	int w;
	w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	glRasterPos2f(X()+Size().x/2, Y()+Size().y/2);
	int len = 2;
	for (int i = 0; i < len; i++) {
	    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
}
