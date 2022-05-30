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
using namespace std;

inline void Inventory::show_trader_artifacts()
{
	for (multiset <string> ::iterator it_trader_inventory = trader_inventory.begin(); it_trader_inventory != trader_inventory.end(); ++it_trader_inventory)
		cout << *it_trader_inventory << endl;
}

// показ надтых артефактов
inline void Inventory::show_weared_artifacts()
{
	for (multiset <string> ::iterator it_weared = weared_inventory.begin(); it_weared != weared_inventory.end(); ++it_weared)
		cout << *it_weared << endl;
}

// показ снятых артифактов
inline void Inventory::show_not_weared_artifacts()
{
	for (multiset <string> ::iterator it_not_weared = weared_inventory.begin(); it_not_weared != weared_inventory.end(); ++it_not_weared)
		cout << *it_not_weared << endl;
}

inline bool Inventory::take_artifact_trader(string str)
{
	if (trader_inventory.size() > 0 && trader_inventory.find(str) != trader_inventory.end())
	{
		not_weared_inventory.insert(str);
		trader_inventory.erase(str);
		return 1;
	}
	return 0;
}

// снять артифакт
inline bool Inventory::take_off_artifact(string str)
{
	if (weared_inventory.size() > 0 && weared_inventory.find(str) != weared_inventory.end())
	{
		not_weared_inventory.insert(str);
		weared_inventory.erase(str);
		return 1;
	}
	return 0;
}

// надеть артифакт
inline bool Inventory::put_on_artifact(string str)
{
	if (not_weared_inventory.size() > 0 && not_weared_inventory.find(str) != not_weared_inventory.end())
	{
		weared_inventory.insert(str);
		not_weared_inventory.erase(str);
		return 1;
	}
	return 0;
}

// приём товара от торговца, ф-я выкидывания его от торговца || готово
// сделать так, чтобы герой мог использовать инвентарь, совместимость .cpp и .h || готово

/* хождение по полю (собирать монеты, артифакты; встреча с монстрами, с торговцами,
их несколько; убрать препятствие, сам подумаю: есть неубирамые, есть убираемые) */

