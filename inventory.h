#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <fstream>
#include <Windows.h>
#include "person.h" 

// не стоит подключать сюдя #include "hero.h", так как возникает ошибка

using namespace std;

// инвентарь
class Inventory
{
public:
	Inventory& operator = (Inventory _help);

public:
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