#pragma once
#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_
#define  MAX_SIZE_MAP 100
#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include <fstream>
#include "inventory.h"
#include "person.h" 
#include "hero.h" 
enum cell 
{	
	stone, tree, gold, orge, skeleton, ghost, dragon
};

// 1 - камень (неубираемое препядствие)
// 2 - дерево (убираемое препядствие)
// 3 - золото (собирать)
// 4 - монстр orge
// 5 - монстр skeleton
// 6 - монстр ghost
// 7 - монстр dragon

class Game_map
{
private:
	int** map; // поле
	int **map_2; // второе поле
	int size_map;
	person user;
	cell obstacle;

public:
	Game_map();
	~Game_map();
	void set_cell(int, int, int);

	//// проверка корректности хода
	//void check_correct_move(Hero &hero);

	// получить номер препядствия (enum)
	cell get_obstacle();

	// передать номер препядствия (enum)
	void set_obstacle(cell obstacle);

	// получить размер поля
	int get_size_map();

	// получить содержимое клетки
	int get_cell(int x, int y);

	// занулил клетку, в которой срубили дерево
	void cut_tree(Hero &hero);

	// отметить посещённую клетку
	void mark_visited_cell(int x, int y);

	// занулить клетку после взятия золота
	void take_gold(Hero &hero);

	// занулить клетку после убийства monster
	void murder_monster(Hero &hero, int num);
};

#endif // _GAME_MAP_H_

