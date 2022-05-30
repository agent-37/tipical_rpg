#include "draw.h"
#include <string>
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include "bmp.h"
#include "C:\Temp\glut-3.7.6-bin\glut.h"
#include "hero.h"
#include "person.h"
#include "game_map.h"

using namespace std;
enum file_monsters { dragon = 1, ghost = 2, spider = 3, skeleton = 4, ogre = 5 };
//функция определяет по направлению влгляда вспомогоательные переменные
void determin_the_direction_construction(int view, int& x, int& y, int& l_x, int& l_y, int& r_x, int& r_y) {
	switch (view) {
	case 1: {
		x = 0;
		y = 1;
		l_x = -1;
		l_y = 0;
		r_x = 1;
		r_y = 0;
		break;
	}
	case 2: {
		x = 1;
		y = 0;
		l_x = 0;
		l_y = 1;
		r_x = 0;
		r_y = -1;
		break;
	}
	case 3: {
		x = 0;
		y = -1;
		l_x = 1;
		l_y = 0;
		r_x = -1;
		r_y = 0;
		break;
	}
	case 4: {
		x = -1;
		y = 0;
		l_x = 0;
		l_y = -1;
		r_x = 0;
		r_y = +1;
		break;
	}
	}
}
//функция рисует картинку (x,y левый нижний угол картинки)
void draw_picture(int x, int y, const char* file_name) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bitmap picture(file_name);
	int h = picture.height(), w = picture.width();
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {
			bmp_rgb pixel = picture.get(j, i);
			glColor3ub((int)pixel.red(), (int)pixel.green(), (int)pixel.blue());
			glBegin(GL_POINTS);
			glVertex2f(x + (i), y + (h - j));
			glEnd();
		}

}

void draw_walk(Hero user, game_map map) {
	draw_picture(0, 0, "back.bmp");
	//определяем где герой на карте и направление взора
	int x = user.get_x();
	int y = user.get_y();
	int view = user.get_direction_gaze();
	//вспомогательные переменные для утановки клеток перед игроком
	int opposite_x, opposite_y, left_x, left_y, right_x, right_y;
	determin_the_direction_construction(view, opposite_x, opposite_y, left_x, left_y, right_x, right_y);
	int  size_map = map.get_size_field();
	//строим клетку (которая находится через 1 от игрока)
	if ((x + 3 * opposite_x) >= 0 && (x + 3 * opposite_x) < size_map && (y + 3 * opposite_y) >= 0 && (y + 3 * opposite_y) < size_map) {
		if (map.contents_cell(x + 2 * opposite_x + left_x, y + 2 * opposite_y + left_y) != 1
			&& map.contents_cell(x + 2 * opposite_x + left_x, y + 2 * opposite_y + left_y) != 2)
			draw_picture(420, 322, "second_left_door.bmp");
		if (map.contents_cell(x + 2 * opposite_x + right_x, y + 2 * opposite_y + right_y) != 1
			&& map.contents_cell(x + 2 * opposite_x + right_x, y + 2 * opposite_y + right_y) != 2)
			draw_picture(800, 322, "second_right_door.bmp");
		if (map.contents_cell(x + 3 * opposite_x, y + 3 * opposite_y) != 1 && map.contents_cell(x + 3 * opposite_x, y + 3 * opposite_y) != 2)
			draw_picture(530, 408, "third_block_fog.bmp");
		else
			if (map.contents_cell(x + 3 * opposite_x, y + 3 * opposite_y) == 1)
				draw_picture(530, 408, "third_block_break.bmp");
			else
				draw_picture(530, 408, "third_block_unbreak.bmp");
	}
	//строим клетку которая напротив игрока
	if ((x + 2 * opposite_x) >= 0 && (x + 2 * opposite_x) < size_map && (y + 2 * opposite_y) >= 0 && (y + 2 * opposite_y) < size_map) {
		if (map.contents_cell(x + opposite_x + left_x, y + opposite_y + left_y) != 1
			&& map.contents_cell(x + opposite_x + left_x, y + opposite_y + left_y) != 2)
			draw_picture(150, 114, "first_left_door.bmp");
		if (map.contents_cell(x + opposite_x + right_x, y + opposite_y + right_y) != 1
			&& map.contents_cell(x + opposite_x + right_x, y + opposite_y + right_y) != 2)
			draw_picture(1000, 114, "first_right_door.bmp");

		if (map.contents_cell(x + 2 * opposite_x, y + 2 * opposite_y) != 1 && map.contents_cell(x + 2 * opposite_x, y + 2 * opposite_y) != 2) {
			draw_picture(350, 268, "third_block_fog.bmp");//нужно прописать кто или что там стоит всех всех
		}
		else
			if (map.contents_cell(x + 2 * opposite_x, y + 2 * opposite_y) == 1)
				draw_picture(350, 268, "second_block_break.bmp");
			else
				draw_picture(350, 268, "second_block_unbreak.bmp");
	}
	//строим клетку в которой стоим
	if (map.contents_cell(x + opposite_x, y + opposite_y) != 1 && map.contents_cell(x + opposite_x, y + opposite_y) != 2) {
		draw_picture(100, 76, "third_block_fog.bmp");//нужно прописать кто или что там стоит всех всех
	}
	else
		if (map.contents_cell(x + opposite_x, y + opposite_y) == 1)
			draw_picture(100, 76, "first_block_break.bmp");
		else
			draw_picture(100, 76, "first_block_unbreak.bmp");
}

void draw_mini_map(Hero user, game_map map, int y, int x) {
	int map_x = user.get_x(), map_y = user.get_y();
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++) {
			if (!map.visited(map_x, map_y))
				glColor3ub(51, 51, 51);
			else
				switch (map.contents_cell(map_x, map_y)) {
				case empty_cell: {
					glColor3ub(255, 255, 0);
					break;
				}
				case traeder: {
					glColor3ub(51, 204, 51);
					break;
				}
				}
			glBegin(GL_QUADS);
			glVertex2f(x + 7 * i, y + 7 * j);
			glVertex2f(x + 7 * (i + 1), y + 7 * j);
			glVertex2f(x + 7 * (i + 1), y + 7 * (j + 1));
			glVertex2f(x + 7 * i, y + 7 * (j + 1));
			glEnd();
		}
}