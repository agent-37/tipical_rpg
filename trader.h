#ifndef _TRADER_H_
#define _TRADER_H_
#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <fstream>
#include <Windows.h>
#define name_file "artifacts.txt"
using namespace std;

class Trader
{
public:
	Trader();
	~Trader();

	// продать инвентарь герою
	bool trade_inventory(string inventory);

	// взять инвентарь со склада
	bool take_inventory_from_warehouse(string str);

	// положить инвентарь на склад	
	bool put_inventory_on_warehouse(string str);

	// показать инвернтарь торговца
	void show_inventory_trader();

protected:
	// мультисет артифактов торговца
	multiset <pair<string, int>> trader_inventory;

	// мультисет артефактов склада
	multiset <string> warehouse_inventory;

	// итератор на мультисет артифактов торговца (для добавления и удаления в ходе игры)
	multiset <pair<string, int>> ::iterator it_trader_inventory;

	// итератор на мультисет артефактов склада
	multiset <string> it_warehouse_inventory;

	// прибыль продавца
	int revenue;
};

#endif // _TRADER_H_