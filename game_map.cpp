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

// �����������
Game_map::Game_map()
{
	fstream fin("input.txt", fstream::in | fstream::out | fstream::app); // ����� ��� ������� ����������� � ����
	fin >> size_map;

	// �������� ����
	map = new int *[size_map];
	for (int i = 0; i < size_map; i++)
		map[i] = new int[size_map] {};

	// �������� ������� ����
	map_2 = new int *[size_map];
	for (int i = 0; i < size_map; i++)
		map_2[i] = new int[size_map] {};

	// ������ ���� �� �����
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

// ����������
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
		delete[] map_2[i];
		map_2[i] = nullptr;
	}
	delete[] map_2;
	map_2 = nullptr;
}

// ��������� �������� ������
void Game_map::set_cell(int x, int y, int value)
{
	map[x][y] = value;
}

//// �������� ������������ ����
//void Game_map::check_correct_move(Hero &hero)
//{
//	// 1 - ������ (����������� �����������)
//	// 2 - ������ (��������� �����������)
//	if ( (map[hero.get_x()][hero.get_y()] == 1) || (map[hero.get_x()][hero.get_y()] == 2))
//		// �������
//}

// ��������� ������� ����
int Game_map::get_size_map()
{
	return size_map;
}

// ��������� ����������� ������
int Game_map::get_cell(int x, int y)
{
	return map[x][y];
}

// �������� ������ ����� ������ ������
void Game_map::take_gold(Hero &hero)
{
	if (map[hero.get_x()][hero.get_y()] == 3)
		map[hero.get_x()][hero.get_y()] = 0;
}

// �������� ������ ����� �������� monster
void Game_map::murder_monster(Hero &hero, int num)
{
	if (map[hero.get_x()][hero.get_y()] == 4 || map[hero.get_x()][hero.get_y()] == 5 ||
		map[hero.get_x()][hero.get_y()] == 6 || map[hero.get_x()][hero.get_y()] == 7)
		map[hero.get_x()][hero.get_y()] = 0;

}

//  �������� ������, � ������� ������� ������
void Game_map::cut_tree(Hero &hero)
{
	if (hero.step_f == &Hero::step_forward && map[hero.get_y() + 1][hero.get_x()] == 2)
		map[hero.get_y() + 1][hero.get_x()] = 0;
	else if (hero.step_f == &Hero::step_left && map[hero.get_y()][hero.get_x() - 1] == 2)
		map[hero.get_y()][hero.get_x() - 1] = 0;
	else if (hero.step_f == &Hero::step_right && map[hero.get_y()][hero.get_x() + 1] == 2)
		map[hero.get_y()][hero.get_x() + 1] = 0;
	else if (hero.step_f == &Hero::step_back && map[hero.get_y() - 1][hero.get_x()] == 2)
		map[hero.get_y() - 1][hero.get_x()] = 0;
}

// ������� ���������� ������
void Game_map::mark_visited_cell(int x, int y)
{
	map_2[x][y] = 1;
}

int Game_map::visited(int x, int y) {
	return map_2[x][y];
}

// enum �����������, �������, 
// ��������
// ������� ������� ������, ��� ��������� � ������ (��� � draw.cpp)
// �������, ���� ����� � �������������� ������
// ����������� �������� ������ 