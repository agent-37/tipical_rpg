#pragma once
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

enum dir_gaze
{
	forward, right, back, left, tmp_viev
};

// герой
class Hero : public person
{
private:
	// указатель на функцию класса
	typedef bool (Hero::* func_ptr)(void);
	int x, y;	// координаты положения героя
	int direction_gaze; // направление взгляда
						// 1 - вперёд
						// 2 - вправо
						// 3 - назад
						// 2 - влево
	int count_healing_poison; // количество зелья
	int num_recovery_units_poison; // количество восполняемого HP
	Inventory inventory_user;
	dir_gaze view;

public:
	Hero();
	~Hero();

	// восполнение здоровья 
	void healing_poison();

	// показ характеристик героя
	void show_characteristics();

	// шаг вперёд
	bool step_forward();
	bool (Hero::* step_f)() = &Hero::step_forward;
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

	// получить направление взгляда
	int get_direction_gaze();

	// передать координату х героя
	void set_x(int x);

	// передать координату y героя
	void set_y(int y);

	// передать новую броню
	void set_armor(int x);

	// передать max_health
	void set_max_health(int x);

	// получить координату х героя
	int get_x();

	// получить координату y героя
	int get_y();

	// получить  максимальное хп
	int get_max_health();

	// получить нынешнее здоровье
	int get_health();

	//получить золото
	int get_gold();

	// получить  броню
	int get_armor();

	// поворот вправо 
	void turn_right();

	// поворот влево 
	void turn_left();

};

#endif // _HERO_H_