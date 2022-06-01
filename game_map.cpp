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

Game_map::Game_map()
{
	fstream fin(name_file, fstream::in | fstream::out | fstream::app); // ����� ��� ������� ����������� � ����
	fin >> size_map; // ����� ��� ������� ����������� � ���� � ��������� �� ������ � ��������� ������������

	if (!fin.is_open())
		cout << "���� �� ������" << endl;

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
			fin >> map[i][j];

	// ����������� ������� ���� �� ������ ����
	for (int i = 0; i < size_map; i++)
		for (int j = 0; j < size_map; j++)
			map_2[i][j] = map[i][j];

	for (int i = 0; i < size_map; i++)
	{
		for (int j = 0; j < size_map; j++)
			cout << map[i][j];
		cout << endl;
	}

	fin.close();
}

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

// ������� ������, ������� �� ����
void Game_map::cut_tree(Hero &hero)
{

	if (hero.step_f == &Hero::step_forward && map[hero.get_y() + 1][hero.get_x()] == 3)
	{
		map[hero.get_y() + 1][hero.get_x()] = 0;
		user.gold++;
	}
	else if (hero.step_f == &Hero::step_left && map[hero.get_y()][hero.get_x() - 1] == 3)
	{
		map[hero.get_y()][hero.get_x() - 1] = 0;
		user.gold++;
	}
	else if (hero.step_f == &Hero::step_right && map[hero.get_y()][hero.get_x() + 1] == 3)
	{
		map[hero.get_y()][hero.get_x() + 1] = 0;
		user.gold++;
	}
	else if (hero.step_f == &Hero::step_back && map[hero.get_y() - 1][hero.get_x()] == 3)
	{
		map[hero.get_y() - 1][hero.get_x()] = 0;
		user.gold++;
	}
}

void Game_map::take_gold(Hero &hero)
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

// enum �����������, �������, 
// ��������
// ������� ������� ������, ��� ��������� � ������ (��� � draw.cpp)
// �������, ���� ����� � �������������� ������
// ����������� �������� ������ 


int main()
{
	// ����
	Game_map game_map;
	Hero herot;
	setlocale(LC_ALL, "rus");
	cout << to_string(1) << " ��������� ������" << endl;
	herot.show_characteristics();
	cout << endl << endl;

	herot.call_step_r();
	cout << to_string(2) << " ������ ��� ������" << endl;
	herot.show_characteristics();
	cout << endl << endl;

	herot.turn_left();
	cout << to_string(3) << " ������� �����, �� ������ �� ������ ����������" << endl;
	herot.show_characteristics();
	cout << endl << endl;

	herot.call_step_r();
	cout << to_string(4) << " ��� ������ ������ �������� ������ ����������" << endl;
	herot.show_characteristics();
	cout << endl << endl;

	system("pause");
	return 0;
}

