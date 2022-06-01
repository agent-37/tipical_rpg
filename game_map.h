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
	person user;

public:
	Game_map();
	~Game_map();
	void set_cell(int, int, int);

	//// �������� ������������ ����
	//void check_correct_move(Hero &hero);

	// �������� ������ ����
	int get_size_map();

	// �������� ���������� ������
	int get_cell(int x, int y);

	//  �������� ������, � ������� ������� ������
	void cut_tree(Hero &hero);

	// �������� ���������� ������
	void mark_visited_cell(int x, int y);

	// �������� ������ ����� ������ ������
	void take_gold(Hero &hero);

	// �������� ������ ����� �������� monster
	void murder_monster(Hero &hero, int num);
};

#endif // _GAME_MAP_H_


