#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <fstream>
#include <Windows.h>
#include "trader.h"
#include "hero.h"
#include "inventory.h"
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

enum art { buy_art = 1, cant_buy = 2, not_find = 0 };

//читаем из файла все артифакты(название и цену)
Trader::Trader()
{
	fstream fin(name_file, fstream::in | fstream::out | fstream::app);
	for (int i = 0; i < 15; i++)
	{
		string el;
		int cost, chance;
		fin >> el >> cost;
		artifact.insert(make_pair(el, cost));
	}

	fin.close();
}

Trader::~Trader()
{
}

// продать артефакт герою
int Trader::trade_inventory(string art, Hero& user)
{
	if (trader_inventory.find(art) != trader_inventory.end())
	{
		if (user.get_gold() >= artifact[art]) {
			trader_inventory.erase(art);
			user.add_artifact(art);
			user.set_gold(user.get_gold() - artifact[art]);
			return buy_art;
		}
		return cant_buy;
	}
	return not_find;
}

//заполнение лавки торговца
void Trader::fill_inventory_trader()
{
	srand(time(NULL));
	while (trader_inventory.size() != 5) {
		int chance = rand() % 15;
		map<string, int> ::iterator it_help;
		it_help = artifact.begin();
		for (int i = 0; i < chance; i++)
			it_help++;
		trader_inventory.insert(it_help->first);
	}
}


// показать инвернтарь торговца
void Trader::show_inventory_trader()
{
	for (const auto& el : trader_inventory)
	{
		cout << el << ' ' << artifact[el] << endl;
	}
}
