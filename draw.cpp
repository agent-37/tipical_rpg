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
#include "monsters.h"
using namespace std;

enum file_monsters { empty_cell = 0, unbreakable = 1, breakable = 2, heep_gold = 3, _ogre = 4, _skeleton = 5, _ghost = 6, _dragon = 7, _trader = 8 };
// 0 - пусто
// 1 - камень (неубираемое препядствие)
// 2 - дерево (убираемое препядствие)
// 3 - золото (собирать)
// 4 - монстр orge
// 5 - монстр skeleton
// 6 - монстр ghost
// 7 - монстр dragon
// 8 - торговец
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
//функция рисует изображение без 1 цвета(как хромакей)
void draw_picture_hrom(int x, int y, const char* file_name) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bitmap picture(file_name);
	int h = picture.height(), w = picture.width();
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {
			bmp_rgb pixel = picture.get(j, i);
			if ((int)pixel.red() != 0 || (int)pixel.green() != 0 || (int)pixel.blue() != 255) {
				glColor3ub((int)pixel.red(), (int)pixel.green(), (int)pixel.blue());
				glBegin(GL_POINTS);
				glVertex2f(x + (i), y + (h - j));
				glEnd();
			}
		}

}
//процедура рисование картинки ходьбы
void draw_walk(Hero user, Game_map& map) {
	draw_picture(0, 0, "back.bmp");

	//определяем где герой на карте и направление взора
	int x = user.get_x();
	int y = user.get_y();

	int view = user.get_direction_gaze();
	//вспомогательные переменные для утановки клеток перед игроком
	int opposite_x = 0, opposite_y = 0, left_x = 0, left_y = 0, right_x = 0, right_y = 0;
	determin_the_direction_construction(view, opposite_x, opposite_y, left_x, left_y, right_x, right_y);
	int  size_map = map.get_size_map();
	//строим клетку (которая находится через 1 от игрока)
	if ((x + 3 * opposite_x) >= 0 && (x + 3 * opposite_x) < size_map
		&& (y + 3 * opposite_y) >= 0 && (y + 3 * opposite_y) < size_map
		&& map.get_cell(x + 2 * opposite_x, y + 2 * opposite_y) != unbreakable
		&& map.get_cell(x + 2 * opposite_x, y + 2 * opposite_y) != breakable
		&& map.get_cell(x + opposite_x, y + opposite_y) != unbreakable
		&& map.get_cell(x + opposite_x, y + opposite_y) != breakable)
	{
		if (map.get_cell(x + 2 * opposite_x + left_x, y + 2 * opposite_y + left_y) != unbreakable
			&& map.get_cell(x + 2 * opposite_x + left_x, y + 2 * opposite_y + left_y) != breakable
			)
			draw_picture_hrom(420, 322, "second_left_door.bmp");

		if (map.get_cell(x + 2 * opposite_x + right_x, y + 2 * opposite_y + right_y) != unbreakable
			&& map.get_cell(x + 2 * opposite_x + right_x, y + 2 * opposite_y + right_y) != breakable)
			draw_picture_hrom(800, 322, "second_right_door.bmp");

		if (map.get_cell(x + 3 * opposite_x, y + 3 * opposite_y) != unbreakable && map.get_cell(x + 3 * opposite_x, y + 3 * opposite_y) != breakable)
			draw_picture(530, 408, "third_block_fog.bmp");
		else
			if (map.get_cell(x + 3 * opposite_x, y + 3 * opposite_y) == unbreakable)
				draw_picture(530, 408, "third_block_unbreak.bmp");
			else
				draw_picture(530, 408, "third_block_break.bmp");
	}

	//строим клетку которая напротив игрока
	if ((x + 2 * opposite_x) >= 0 && (x + 2 * opposite_x) < size_map
		&& (y + 2 * opposite_y) >= 0 && (y + 2 * opposite_y) < size_map
		&& map.get_cell(x + opposite_x, y + opposite_y) != unbreakable
		&& map.get_cell(x + opposite_x, y + opposite_y) != breakable) {
		if (map.get_cell(x + opposite_x + left_x, y + opposite_y + left_y) != unbreakable
			&& map.get_cell(x + opposite_x + left_x, y + opposite_y + left_y) != breakable)
			draw_picture(150, 114, "first_left_door.bmp");
		if (map.get_cell(x + opposite_x + right_x, y + opposite_y + right_y) != unbreakable
			&& map.get_cell(x + opposite_x + right_x, y + opposite_y + right_y) != breakable)
			draw_picture(1000, 114, "first_right_door.bmp");


		if (map.get_cell(x + 2 * opposite_x, y + 2 * opposite_y) != unbreakable && map.get_cell(x + 2 * opposite_x, y + 2 * opposite_y) != breakable) {
			switch (map.get_cell(x + 2 * opposite_x, y + 2 * opposite_y))
			{
			case (_ogre): {
				draw_picture_hrom(470, 322, "ogre_mini.bmp");
				break;
			}
			case (_dragon): {
				draw_picture_hrom(470, 322, "dragon_mini.bmp");
				break;
			}
			case (_skeleton): {
				draw_picture_hrom(470, 322, "skeleton_mini.bmp");
				break;
			}
			case (_ghost): {
				draw_picture_hrom(470, 322, "ghost_mini.bmp");
				break;
			}
			case (_trader): {
				draw_picture_hrom(470, 322, "trader_mini.bmp");
				break;
			}
			}
		}
		else
			if (map.get_cell(x + 2 * opposite_x, y + 2 * opposite_y) == unbreakable)
				draw_picture(350, 268, "second_block_unbreak.bmp");
			else
				draw_picture(350, 268, "second_block_break.bmp");
	}

	//строим клетку в которой стоим
	if (map.get_cell(x + opposite_x, y + opposite_y) != unbreakable && map.get_cell(x + opposite_x, y + opposite_y) != breakable) {

		switch (map.get_cell(x + opposite_x, y + opposite_y))
		{
		case (_ogre): {
			draw_picture_hrom(650, 130, "ogre.bmp");
			break;
		}
		case (_dragon): {
			draw_picture_hrom(650, 130, "dragon.bmp");

			break;
		}
		case (_ghost): {
			draw_picture_hrom(650, 130, "ghost.bmp");
			break;
		}
		case (_skeleton): {
			draw_picture_hrom(650, 130, "skeleton.bmp");
			break;
		}
		case (_trader): {
			draw_picture_hrom(650, 130, "trader.bmp");
			break;
		}
		}
	}
	else
		if (map.get_cell(x + opposite_x, y + opposite_y) == unbreakable)
			draw_picture(100, 76, "first_block_unbreak.bmp");
		else
			draw_picture(100, 76, "first_block_break.bmp");
	glFinish();
}
//процедура рисует мини карту
void draw_mini_map(Hero user, Game_map& map, int x, int y) {
	int map_x = user.get_x(), map_y = user.get_y();
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++) {
			if (!map.visited(map_x + i - 3, map_y + j - 3))
				glColor3ub(51, 51, 51);
			else
				switch (map.get_cell(map_x + i - 3, map_y + j - 3)) {
				case empty_cell: {
					glColor3ub(255, 255, 0);
					break;
				}
				case _trader: {
					glColor3ub(51, 204, 51);
					break;
				}
				default: {glColor3ub(0, 0, 0); }
				}
			glBegin(GL_QUADS);
			glVertex2f(x + 28 * i, y + 28 * j);
			glVertex2f(x + 28 * (i + 1), y + 28 * j);
			glVertex2f(x + 28 * (i + 1), y + 28 * (j + 1));
			glVertex2f(x + 28 * i, y + 28 * (j + 1));
			glEnd();
		}
	glFinish();
}

//рисует полоску хп
void draw_hp(int x, int y, int health, int max_health) {

	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + 50, y);
	glVertex2f(x + 50, y + 800);
	glVertex2f(x, y + 800);
	glEnd();
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + 50, y);
	glVertex2f(x + 50, y + max(800 * health / max_health, 0));
	glVertex2f(x, y + max(800 * health / max_health, 0));
	glEnd();
	glFinish();
}
//рисует картинку для фазы боя
void draw_fight(Hero user, person& monster, int mark) {
	draw_picture(0, 0, "back_fight.bmp");

	//высвечиваются полоски хп с макимумом на заднем фоне
	int hero_hp = user.get_health(), monster_hp = monster.health;
	int max_hero_hp = user.get_max_health(), max_monster_hp = monster.health;

	draw_picture_hrom(100, 50, "hero.bmp");
	draw_hp(50, 50, user.get_health(), user.get_max_health());
	draw_hp(1200, 50, monster.health, monster.max_health);
	switch (mark) {
	case(_ogre): {
		draw_picture_hrom(750, 50, "ogre_fight.bmp");
		break;
	}
	case(_dragon): {
		draw_picture_hrom(750, 50, "dragon_fight.bmp");
		break;
	}
	case(_skeleton): {
		draw_picture_hrom(750, 50, "skeleton_fight.bmp");
		break;
	}
	case(_ghost): {
		draw_picture_hrom(750, 50, "ghost_fight.bmp");
		break;
	}
	}
	glFinish();
}
