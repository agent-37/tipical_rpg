#include <iostream> 
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
#include "trader.h"
using namespace std;

// показ надтых артефактов
void Inventory::show_weared_artifacts()
{
	for (const auto& el : weared_inventory)
		cout << el << endl;
}

// показ снятых артифактов
void Inventory::show_not_weared_artifacts()
{
	for (const auto& el : not_weared_inventory)
		cout << el << endl;
}

// взять артифакт у торговца

// снять артифакт
bool Inventory::take_off_artifact(string str)
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
bool Inventory::put_on_artifact(string str)
{
	if (not_weared_inventory.size() > 0 && not_weared_inventory.find(str) != not_weared_inventory.end())
	{
		weared_inventory.insert(str);
		not_weared_inventory.erase(str);
		return 1;
	}
	return 0;
}

Inventory& Inventory::operator = (Inventory _help) {
	Inventory new_help;
	_help.it_weared = _help.weared_inventory.begin();
	while (_help.it_weared != _help.weared_inventory.end()) {
		new_help.weared_inventory.insert(*_help.it_weared);
		_help.it_weared++;
	}
	_help.it_not_weared = _help.not_weared_inventory.begin();
	while (_help.it_not_weared != _help.not_weared_inventory.end()) {
		new_help.not_weared_inventory.insert(*_help.it_not_weared);
		_help.it_not_weared++;
	}
	return new_help;

}
// приём товара от торговца, ф-я выкидывания его от торговца || готово
// сделать так, чтобы герой мог использовать инвентарь, совместимость .cpp и .h || готово

/* хождение по полю (собирать монеты, артифакты; встреча с монстрами, с торговцами,
их несколько; убрать препятствие, сам подумаю: есть неубирамые, есть убираемые) */