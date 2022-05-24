﻿#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include "person.h" 

using namespace std;

// инвентарь
class Inventory
{
public:
	// показать надтые артефакты
	void show_weared_artifacts();
	// показать снятые артефакты
	void show_not_weared_artifacts();
	// снять артифакт
	string take_off_artifact(string str);
	// надеть артифакт
	string put_on_artifact(string str);

private:
	// мультисет надетых артифактов
	multiset <string> weared_inventory;
	// мультисет снятых артифактов
	multiset <string> not_weared_inventory;


	// итератор на мультисет надетых артифактов (для добавления и удаления в ходе игры)
	multiset <string> ::iterator it_weared;
	// итератор на мультисет снятых артифактов (для добавления и удаления в ходе игры)
	multiset <string> ::iterator it_not_weared;

};

#endif // _INVENTORY_H_
