#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
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
