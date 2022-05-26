#include "draw.h"
#include "hero.h"
#include <string>
#include "bmp.h"
#include "game_map.h"
#include "person.h"
#include "C:\Temp\glut-3.7.6-bin\glut.h"
using namespace std;

GLint Width = 1024, Height = 1024;

void draw_picture(int y, int x, char* file_name) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);    
	bitmap picture(file_name);
	int h = picture.height(), w = picture.width();
	for (int i = 0; i < w; i++) 
		for (int j = 0; j < h; j++) {
			bmp_rgb pixel = picture.get(j,i);
			glColor3ub((int)pixel.red(), (int)pixel.green(), (int)pixel.blue());
			glBegin(GL_QUADS);//почему то ругается?? (не подключал opengl в конфигах)
			glVertex2f((i) * 2, (h - j) * 2);
			glVertex2f((i + 1) * 2, (h - j) * 2);
			glVertex2f((i + 1) * 2, (h - j + 1) * 2);
			glVertex2f((i) * 2, (h - j + 1) * 2);
			glEnd();
		}
	
}