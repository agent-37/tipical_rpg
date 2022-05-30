#ifndef _HERO_H_
#define _HERO_H_

#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <fstream>
#include <Windows.h>
#include "inventory.h"
#include "person.h" 
using namespace std;

// герой
class Hero
{
private:
	int x, y;	// координаты положения героя
	int direction_gaze; // направление взгляда
	int count_healing_poison; // количество зелья
	int num_recovery_units_poison; // количество восполняемого HP
	int** field_array; // поле
	int size_field;
	person user;
	Inventory inventory_user;
	// указатель на функцию класса
	typedef bool (Hero::* func_ptr)(void);

public:
	Hero();	
	~Hero();

	// восполнение здоровья 
	void healing_poison();

	// показ характеристик героя
	void show_characteristics();

	// шаг вперёд
	bool step_forward();
	bool (Hero::* step_f)() { &Hero::step_forward };
	void call_step_f() { (this->*step_f)(); }

	// шаг вправо 
	bool step_right();
	bool (Hero::* step_r)() { &Hero::step_right };
	void call_step_r() { (this->*step_r)(); }

	// шаг назад
	bool step_back();
	bool (Hero::* step_b)() { &Hero::step_back };
	void call_step_b() { (this->*step_b)(); }

	// шаг влево
	bool step_left();
	bool (Hero::* step_l)() { &Hero::step_left };
	void call_step_l() { (this->*step_l)(); }

	// поворот вправо 
	void turn_right();

	// поворот влево 
	void turn_left();

	// срубить дерево, стоящее на пути
	void cut_tree();

	// взять золото
	void take_gold();

	// получить размер поля
	int get_size_field();

};

#endif // _HERO_H_