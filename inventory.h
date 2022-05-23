﻿#include <iostream> 
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

	// надетые артифакты
	multiset <string> weared_inventory;
	// снятые артифакты
	multiset <string> not_weared_inventory;


	// надетые артифакты : итератор
	multiset <string> ::iterator it_weared;
	// снятые артифакты : итератор
	multiset <string> ::iterator it_not_weared;

	// !!!!!!!!!!!!!!!!
	// возможность выбора снимаемого и надеваемого артифакта
	// комменты
	// тест
	// конструкторы 
	// реализ поворот (недоделан)

	//Hero herot;
	//herot.show_characteristics();
	//herot.step_right();
	//cout << to_string(1) << endl;
	//herot.show_characteristics();
	//cout << to_string(1) << endl;
	//herot.turn_left();
	//cout << to_string(1) << endl;
	//herot.step_r();
	//cout << to_string(1) << endl;
	//herot.show_characteristics();
	//cout << to_string(1) << endl;
	
};
