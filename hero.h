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

public:
	Hero();
	~Hero();

	// восполнение здоровья 
	int healing_poison();

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

	int  get_count_healing_poison();
	int  get_num_recovery_units_poison();
	Inventory get_inventory_user();
	Hero& operator = (Hero _user);
	void set_direction_gaze(int _direction_gaze);
	void set_count_healing_poison(int _count_healing_poison);
	void set_num_recovery_units_poison(int _num_recovery_units_poison);
	void set_inventory_user(Inventory _inventory_user);
	void add_artifact(string art);
	void set_gold(int _gold);
	void show_un_wear_art();
	void show_wear_art();
	int un_wear_art(string art);
	int wear_art(string art);
	void add_potion();
};

struct Hero_and_map {
public:
	Hero user;
	int mark[5];
	bool visited;
	Hero_and_map() {}
	~Hero_and_map() {}
public:
	void set(Hero& _user, int _mark[5], int _visited) {
		user = _user;
		for (int i = 0; i < 5; i++)
			mark[i] = _mark[i];
		visited = _visited;
	}
	Hero_and_map& operator =(Hero_and_map _help) {
		user = _help.user;
		for (int i = 0; i < 5; i++)
			mark[i] = _help.mark[i];
		visited = _help.visited;
		return *this;
	}
};
#endif // _HERO_H_