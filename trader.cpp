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

// показать инвернтарь торговца
void Trader::show_inventory_trader()
{
	for (const auto& el : trader_inventory)
	{
		cout << el << endl;
	}
}


