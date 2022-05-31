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
enum cell  {	};

class game_map 
{
private:
	int** map; // поле
	int size_map;
public:
	game_map();
	~game_map();
	void generation();
	void set_cell(int, int, int);
	int get_size_map() { return 100; /*должен возвращать размер поля */}
	int get_cell(int x, int y) { return map[x][y]; }

	Hero hero;

	// срубить дерево, стоящее на пути
	void cut_tree();

	// взять золото
	void take_gold();

	// получить размер поля
	int get_size_map();

	// содержимое клетки
	int get_cell(int i, int j);
};

#endif // _GAME_MAP_H_


