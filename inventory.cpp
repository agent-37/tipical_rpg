#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include "inventory.h"
#include "person.h" 
using namespace std;

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

// снять артифакт
inline string Inventory::take_off_artifact(string str)
{
	if (weared_inventory.size() > 0 && weared_inventory.find(str) != weared_inventory.end())
	{
		not_weared_inventory.insert(str);
		weared_inventory.erase(str);
		return "Готово!\n";
	}
	return "Этот артифакт снят.\n";
}

// надеть артифакт
inline string Inventory::put_on_artifact(string str)
{
	if (not_weared_inventory.size() > 0 && not_weared_inventory.find(str) != not_weared_inventory.end())
	{
		weared_inventory.insert(str);
		not_weared_inventory.erase(str);
		return "Готово!\n";
	}
	return "Этот артифакт уже надет.\n";
}

// приём товара от торговца, ф-я выкидывания его от торговца
// сделать так, чтобы герой мог использовать инвентарь, совместимость .cpp и .h

/* хождение по полю (собирать монеты, артифакты; встреча с монстрамиб с торговцами,
их несколько; убрать препятствие, сам подумаю: есть неубирамые, есть убираемыеа) */


