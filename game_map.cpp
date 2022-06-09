#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include <fstream>
#include "inventory.h"
#include "game_map.h"
#include "person.h" 
#include "hero.h" 
#define name_file "game_map1.txt"
using namespace std;

// конструктор
Game_map::Game_map()
{
	fstream fin(name_file, fstream::in | fstream::out | fstream::app); // позже это следует переместить в мейн
	fin >> size_map;
	// создание поля
	map = new int* [size_map];
	for (int i = 0; i < size_map; i++)
		map[i] = new int[size_map] {};

	// создание второго поля
	map_visit = new int* [size_map];
	for (int i = 0; i < size_map; i++)
		map_visit[i] = new int[size_map] {};

	// чтение поля из файла
	for (int i = 0; i < size_map; i++)
		for (int j = 0; j < size_map; j++)
		{
			char num;
			fin.get(num);
			while (num == '\n' || num == ' ')
				fin.get(num);
			map[j][i] += (num - '0');
		}

	fin.close();
}

// деструктор
Game_map::~Game_map()
{
	for (int i = 0; i < size_map; i++)
	{
		delete[] map[i];
		map[i] = nullptr;
	}
	delete[] map;
	map = nullptr;

	for (int i = 0; i < size_map; i++)
	{
		delete[] map_visit[i];
		map_visit[i] = nullptr;
	}
	delete[] map_visit;
	map_visit = nullptr;
}

// изменение состояни клетки
void Game_map::set_cell(int x, int y, int value)
{
	if (x >= 0 && x <= size_map && y >= 0 && y <= size_map)
		map[x][y] = value;
}

// получение размера поля
int Game_map::get_size_map()
{
	return size_map;
}

// получение содержимого клетки
int Game_map::get_cell(int x, int y)
{
	if (x >= 0 && x <= size_map && y >= 0 && y <= size_map)
		return map[x][y];
	else
		return -1;
}

// занулить клетку после взятия золота
void Game_map::take_gold(Hero& hero)
{
	if (map[hero.get_x()][hero.get_y()] == 3)
		map[hero.get_x()][hero.get_y()] = 0;
}

// занулить клетку после убийства monster
void Game_map::murder_monster(Hero& hero, int num)
{
	if (map[hero.get_x()][hero.get_y()] == 4 || map[hero.get_x()][hero.get_y()] == 5 ||
		map[hero.get_x()][hero.get_y()] == 6 || map[hero.get_x()][hero.get_y()] == 7)
		map[hero.get_x()][hero.get_y()] = 0;

}

//  пометить клетку, в которой срубили дерево
void Game_map::cut_tree(Hero& hero)
{
	switch (hero.get_direction_gaze()) {
	case(1): {if (map[hero.get_x()][hero.get_y() + 1] == 2)
		map[hero.get_x()][hero.get_y() + 1] = 0;
		break;
	}
	case(2): {if (map[hero.get_x() + 1][hero.get_y()] == 2)
		map[hero.get_x() + 1][hero.get_y()] = 0;
		break;
	}
	case(3): {if (map[hero.get_x()][hero.get_y() - 1] == 2)
		map[hero.get_x()][hero.get_y() - 1] = 0;
		break;
	}
	case(4): {if (map[hero.get_x() - 1][hero.get_y()] == 2)
		map[hero.get_x() - 1][hero.get_y()] = 0;
		break;
	}
	}
}

// пометка посещённой клетки
void Game_map::mark_visited_cell(int x, int y)
{
	map_visit[x][y] = 1;
}
//проверка на то что клетка посещена
bool Game_map::visited(int x, int y) {
	if (map_visit[x][y] == 1)
		return true;
	return false;
}
//передать клетку посетили или нет
void Game_map::set_visit(int x, int y, int t) {
	map_visit[x][y] = t;
}
