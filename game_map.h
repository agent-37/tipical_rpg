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
enum cell {	};

class Game_map
{
private:
	int** map; // ����
	int **map_2; // ������ ����
	int size_map;
public:
	Game_map();
	~Game_map();
	void set_cell(int, int, int);

	// �������� ������ ����
	int get_size_map() { return size_map; }

	// ���������� ������
	int get_cell(int x, int y) { return map[x][y]; }

	person user;

	// ������� ������, ������� �� ����
	void cut_tree(Hero &hero);

	// ����� ������
	void take_gold(Hero &hero);

};

#endif // _GAME_MAP_H_


