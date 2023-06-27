#include <GL/glut.h> 
#include <math.h> 
#include <stdbool.h> 
#include <stdio.h> 
#include "tools.h"
#include "world.h"
#include "counterblock.h"
#include "circle.h"
#include "line.h"
#include "platform.h"

float blockWidth = 0.2f; 
float blockHeight = 0.1f; 
float blockSpacing = 0.05f; // Adjust the spacing between blocks 

World *world;
Platform *platform;
Line *ground;
 
void init() 
{
	world = new World();
	platform = new Platform(true, Vector2(0,-1), Vector2(0.3,0.1), Color(0,0,1));
	ground = new Line(Vector2(-1,-1), Vector2(1,-1), Vector2(0,1));
	
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    for (float x=-0.8;x<0.8;x+=blockWidth + blockSpacing)
    {
    	for (float y=0.2;y<0.8;y+=blockHeight + blockSpacing)
	    {
    		world->Add(new CounterBlock(true, Vector2(x,y), Vector2(blockWidth,blockHeight), Color(0,0,1), 30));
		}
	}
	
	Line *line = new Line(Vector2(1,-1), Vector2(1,1), Vector2(-1,0));
	line->SetVisible(false);
	world->Add(line);
	line = new Line(Vector2(-1,-1), Vector2(-1,1), Vector2(1,0));
	line->SetVisible(false);
	world->Add(line);
	line = new Line(Vector2(-1,1), Vector2(1,1), Vector2(0,-1));
	line->SetVisible(false);
	world->Add(line);
	
	ground->SetVisible(false);
	world->Add(ground);
	
	Circle *circle = new Circle(false, 0,0,0.02, Color(1,0,0));
	circle->SetPosition(Tools::RandomNumber(-0.5f,0.5f),0);
	circle->SetVelocity(Vector2(Tools::RandomNumber(-0.5f,0.5f)>0?0.02:-0.02,0.01));
	world->Add(circle);
	
	world->Add(platform);
} 
 
void Resize(int width, int height) 
{ 
    glViewport(0, 0, width, height); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
    glMatrixMode(GL_MODELVIEW); 
}
 
void update(int value) 
{ 
	world->Update(0.03);
    glutPostRedisplay(); 
    glutTimerFunc(10, update, 0); 
    
    if (ground->IsCollided())
    {
    	delete world;
    	init();
	}
	else
	{
		int count = 0;
		const std::vector<Object*> objects = world->GetObjects();
		for(int i=0,c=objects.size();i<c;i++)
		{
			Object* obj = objects[i];
			Block* block = dynamic_cast<Block*>(obj);
			if (block)
				count++;
		}
		if (count <= 0)
		{
			
		}
	}
} 
 
void mouse(int x, int y) 
{
 	platform->SetPosition( (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2.0f - 1.0f,-1);
} 

void Render() 
{ 
 glClear(GL_COLOR_BUFFER_BIT); 
 glLoadIdentity(); 
 world->Draw();
 
 glutSwapBuffers(); 
  
}   

int main(int argc, char** argv) 
{ 
 glutInit(&argc, argv); 
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
 glutInitWindowSize(800, 600); 
 glutCreateWindow("Ball Bouncing Game"); 
 init(); 
 glutDisplayFunc(Render); 
 glutReshapeFunc(Resize); 
 glutTimerFunc(10, update, 0); 
 glutPassiveMotionFunc(mouse); 
 glutMainLoop(); 
 return 0; 
}
