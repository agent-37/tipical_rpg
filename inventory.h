#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include "weapons.h" 
#include "hero.h" 
//#include "person.h" 

using namespace std;

// инвентарь
class Inventory
{
public:

	// показ надтых артефактов
	void show_weared_artifacts();
	// показ снятых артифактов
	void show_not_weared_artifacts();
	// снять артифакты
	void take_off_artifact();
	// надеть артифакты
	void put_on_artifact();


private:

	// оружие
	multiset <string> weapons;
	// надетые артифакты
	multiset <string> weared_inventory;
	// снятые артифакты
	multiset <string> not_weared_inventory;

	// оружие : итератор
	multiset <string> ::iterator it_weapons;
	// надетые артифакты : итератор
	multiset <string> ::iterator it_weared;
	// снятые артифакты : итератор
	multiset <string> ::iterator it_not_weared;

};

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

// снять артифакты
inline void Inventory::take_off_artifact()
{
	if (weared_inventory.size() > 0)
	{
		not_weared_inventory.insert(*(weared_inventory.rbegin()));
		weared_inventory.erase(--weared_inventory.end());
	}
	else
		cout << "Все артифакты сняты" << endl;
}

// надеть артифакты
inline void Inventory::put_on_artifact()
{
	if (not_weared_inventory.size() > 0)
	{
		weared_inventory.insert(*(not_weared_inventory.rbegin()));
		not_weared_inventory.erase(--not_weared_inventory.end());
	}
	else
		cout << "Все артифакты надеты" << endl;
}