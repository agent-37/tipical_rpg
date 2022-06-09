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