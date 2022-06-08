#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <fstream>
#include <Windows.h>
#include "trader.h"
using namespace std;

Trader::Trader()
{
	fstream fin(name_file, fstream::in | fstream::out | fstream::app); 

	for (int i = 0; i < 20; i++)
	{
		string el;
		fin >> el;
		warehouse_inventory.emplace(el);
	}

	fin.close();
}

Trader::~Trader()
{
}

// продать инвентарь герою
bool Trader::trade_inventory(string inventory)
{
	if (trader_inventory.find(inventory) != trader_inventory.end())
	{
		trader_inventory.erase(inventory);
		revenue++;
		return 1;
	}
	return 0;
}

bool Trader::take_inventory_from_warehouse(string inventory)
{
	if (trader_inventory.size() > 0 && trader_inventory.find(str) != trader_inventory.end())
	{
		not_weared_inventory.insert(str);
		trader_inventory.erase(str);
		return 1;
	}
	return 0;
}

bool Trader::put_inventory_on_warehouse(string str)
{
	return false;
}

// показать инвернтарь торговца
void Trader::show_inventory_trader()
{
	for (const auto& el : trader_inventory)
	{
		cout << el << endl;
	}
}


