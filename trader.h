#ifndef _TRADER_H_
#define _TRADER_H_
#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <fstream>
#include <Windows.h>
using namespace std;

class Trader
{
public:
	Trader();
	~Trader();

	// продать инвентарь герою
	bool trade_inventory(string inventory);

	// показать инвернтарь торговца
	void show_inventory_trader();

private:
	// мультисет артифактов торговца
	multiset <string> trader_inventory;

	// итератор на мультисет артифактов торговца (для добавления и удаления в ходе игры)
	multiset <string> ::iterator it_trader_inventory;

	// прибыль продавца
	int revenue;

};


#endif // _TRADER_H_