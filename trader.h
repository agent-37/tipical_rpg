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


	void fill_inventory_trader();

	// положить инвентарь на склад	
	bool put_inventory_on_warehouse(string str);

	// показать инвернтарь торговца
	void show_inventory_trader();
	//купить у торговца
	//bool take_artifact_trader(string str,Inventory& inv);
public:
	// мультисет артифактов торговца
	set <string> trader_inventory;

	map<string, int> artifact;
	// итератор на мультисет артифактов торговца (для добавления и удаления в ходе игры)
	set <string> ::iterator it_trader_inventory;



	// прибыль продавца
	int revenue;
};

#endif // _TRADER_H_