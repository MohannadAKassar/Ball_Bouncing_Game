#include "tools.h"
#include <sys/time.h>

float Tools::RandomNumber(float min, float max)
{
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    srand(ms);
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}

void Tools::DrawCircle(float x, float y, float radius, Color color) 
{ 
    glPushMatrix(); 
    glColor3f(color.r, color.g, color.b); 
    glTranslatef(x, y, 0.0f); 
    glBegin(GL_TRIANGLE_FAN); 
    for (int i = 0; i <= 360; i++) 
    { 
        float angle = 2.0f * M_PI * i / 360.0f; 
        float x = radius * cosf(angle); 
        float y = radius * sinf(angle); 
        glVertex2f(x, y); 
    } 
    glEnd(); 
    glPopMatrix(); 
}
void Tools::DrawRectangle(float x, float y, float width, float height, Color color) 
{ 
    glPushMatrix(); 
    glColor3f(color.r, color.g, color.b); 
    glTranslatef(x, y, 0.0f); 
    glBegin(GL_QUADS); 
    glVertex2f(-width / 2.0f, -height / 2.0f); 
    glVertex2f(width / 2.0f, -height / 2.0f); 
    glVertex2f(width / 2.0f, height / 2.0f); 
    glVertex2f(-width / 2.0f, height / 2.0f); 
    glEnd(); 
    glPopMatrix(); 
} 

double Tools::ShortestDistance(float x1,float y1,float x2,float y2,float x3,float y3)
{
    float px=x2-x1;
    float py=y2-y1;
    float temp=(px*px)+(py*py);
    float u=((x3 - x1) * px + (y3 - y1) * py) / (temp);
    if(u>1){
        u=1;
    }
    else if(u<0){
        u=0;
    }
    float x = x1 + u * px;
    float y = y1 + u * py;

    float dx = x - x3;
    float dy = y - y3;
    double dist = sqrt(dx*dx + dy*dy);
    return dist;

}
