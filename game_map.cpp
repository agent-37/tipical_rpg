#include "game_map.h"
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
#define name_file "game_map1.txt"
using namespace std;

game_map::game_map()
{
	fstream fin(name_file, fstream::in | fstream::out | fstream::app); // позже это следует переместить в мейн
	fin >> size_map; // позже это следует переместить в мейн и принимать по ссылке в параметре конструктора

	// создание поля
	map = new int *[size_map];
	for (int i = 0; i < size_map; i++)
		map[i] = new int[size_map] {};

	// чтение поля из файла
	for (int i = 0; i < size_map; i++)
		for (int j = 0; j < size_map; j++)
			fin >> map[i][j];

	fin.close();
}

game_map::~game_map()
{
	for (int i = 0; i < size_map; i++)
	{
		delete[] map[i];
		map[i] = nullptr;
	}
	delete[] map;
	map = nullptr;
}

void game_map::generation()
{
	
}

void game_map::set_cell(int x,int y, int value) 
{
	map[x][y] = value;
}

// срубить дерево, стоящее на пути
void game_map::cut_tree()
{
	if (hero.step_f == &hero.step_forward && map[y + 1][x] == 3)
	{
		map[y + 1][x] = 0;
		user.gold++;
	}
	else if (hero.step_f == &hero.step_left && map[y][x - 1] == 3)
	{
		map[y][x - 1] = 0;
		user.gold++;
	}
	else if (hero.step_f == &hero.step_right && map[y][x + 1] == 3)
	{
		map[y][x + 1] = 0;
		user.gold++;
	}
	else if (hero.step_f == &hero.step_back && map[y - 1][x] == 3)
	{
		map[y - 1][x] = 0;
		user.gold++;
	}
}

void game_map::take_gold()
{

	if (hero.step_f == &hero.step_forward && map[y + 1][x] == 2)
		map[y + 1][x] = 0;
	else if (hero.step_f == &hero.step_left && map[y][x - 1] == 2)
		map[y][x - 1] = 0;
	else if (hero.step_f == &hero.step_right && map[y][x + 1] == 2)
		map[y][x + 1] = 0;
	else if (hero.step_f == &hero.step_back && map[y - 1][x] == 2)
		map[y - 1][x] = 0;
}

// получить размер поля
int game_map::get_size_map()
{
	return size_map;
}

int game_map::get_cell(int i, int j)
{
	return map[i][j];
}