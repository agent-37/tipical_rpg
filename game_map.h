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
enum cell {	};

class Game_map
{
private:
	int** map; // поле
	int** map_visit; // второе поле с пометкой был или не был там герой
	int size_map;
	person user;

public:
	Game_map();
	~Game_map();
	void set_cell(int, int, int);

	// получить размер поля
	int get_size_map();

	// получить содержимое клетки
	int get_cell(int x, int y);

	// занулил клетку, в которой срубили дерево
	void cut_tree(Hero& hero);

	// отметить посещённую клетку
	void mark_visited_cell(int x, int y);

	// занулить клетку после взятия золота
	void take_gold(Hero& hero);

	// занулить клетку после убийства monster
	void murder_monster(Hero& hero, int num);
	//проверка на то что клетка посещена
	bool visited(int x, int y);
	//передать клетку посетили или нет
	void set_visit(int x, int y, int t);
};

#endif // _GAME_MAP_H_


