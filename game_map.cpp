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
	fstream fin(name_file, fstream::in | fstream::out | fstream::app); // позже это следует переместить в мейн
	fin >> size_map; // позже это следует переместить в мейн и принимать по ссылке в параметре конструктора

	if (!fin.is_open())
		cout << "файл не открыт" << endl;

	// создание пол€
	map = new int *[size_map];
	for (int i = 0; i < size_map; i++)
		map[i] = new int[size_map] {};

	// создание второго пол€
	map_2 = new int *[size_map];
	for (int i = 0; i < size_map; i++)
		map_2[i] = new int[size_map] {};

	// чтение пол€ из файла
	for (int i = 0; i < size_map; i++)
		for (int j = 0; j < size_map; j++)
			fin >> map[i][j];

	// копирование первого пол€ во второе поле
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

// изменение состо€ни клетки
void Game_map::set_cell(int x, int y, int value)
{
	map[x][y] = value;
}

// срубить дерево, сто€щее на пути
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

// enum преп€тстви€, монстры, 
// комменты
// геттеры посещен клетки, что находитс€ в клетке (как в draw.cpp)
// возврат, если попал в несуществующую клетку
// возможность изменить клетку 


int main()
{
	// тест
	Game_map game_map;
	Hero herot;
	setlocale(LC_ALL, "rus");
	cout << to_string(1) << " —озданный объект" << endl;
	herot.show_characteristics();
	cout << endl << endl;

	herot.call_step_r();
	cout << to_string(2) << " —делал шаг вправо" << endl;
	herot.show_characteristics();
	cout << endl << endl;

	herot.turn_left();
	cout << to_string(3) << " ѕоворот влево, но ничего не должно изменитьс€" << endl;
	herot.show_characteristics();
	cout << endl << endl;

	herot.call_step_r();
	cout << to_string(4) << " Ўаг вправо должен изменить другие координаты" << endl;
	herot.show_characteristics();
	cout << endl << endl;

	system("pause");
	return 0;
}

