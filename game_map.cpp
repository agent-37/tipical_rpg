#include "game_map.h"
#include <string>
#include <fstream>
#define name_file "game_map1.txt"
using namespace std;
void game_map::generation() {
	ifstream fin(name_file);
	int size_map;
	fin >> size_map;
	map = new int *[size_map];
	for (int i = 0; i < size_map; i++)
		map[i] = new int[size_map];

	for (int i = 0; i < size_map; i++)
		for (int j = 0; j < size_map; j++)
			fin >> map[i][j];
	fin.close();
}

void game_map::set_cell(int x,int y, int value) {
	map[x][y] = value;
}
