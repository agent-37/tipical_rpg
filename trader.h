#ifndef _TRADER_H_
#define _TRADER_H_
#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <fstream>
#include <Windows.h>
#include <map>
#include "hero.h"
#define name_file "artifacts.txt"
using namespace std;

class Trader
{
public:
	Trader();
	~Trader();

	// продать инвентарь герою
	int trade_inventory(string inventory, Hero& user);

	//заполняем инвентарь торговца	
	void fill_inventory_trader();

	// показать инвернтарь торговца
	void show_inventory_trader();

public:
	// мультисет артифактов торговца
	set <string> trader_inventory;

	//все артифакты в игре
	map<string, int> artifact;

	// итератор на мультисет артифактов торговца (для добавления и удаления в ходе игры)
	set <string> ::iterator it_trader_inventory;
};

#endif // _TRADER_H_