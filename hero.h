#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>
#include "person.h"

using namespace std;

class hero
{
private:
	// координаты поля
	int x, y;
	int direction_gaze;

	multiset <string> weapons;

	multiset <string> weared_inventory;
	/*
	* 
	*/

	multiset <string> not_weared_inventory;
	/*
	* 	
	*/

	int count_healing_poison;
	int num_recovery_units_poison; // позже решим, кол-во хп на сколько регенит зелье

	/*
	* вопрос: будет ли видно героя во время игры? если нет, то реализация брони будет просто += 1;
	*/

	person user;

public:
	multiset <string> ::iterator it(string thing);

	// регенерация
	void healing_poison();

	/*
	
	допы
	void use поиск в мультисете
	void надеть 
	void снять
	class артифакты для инвенторя (классы)
	void показать, то надето
	void показать, то снято
	
	*/
	// использование оружия
	void use_weapon();

	void show_armor();

	// шаг вперёд
	void step_forward() { y += 1; }
	void (Hero::* step_f)() { &step_forward };

	// шаг вправо
	void step_right() { x += 1; }
	void (Hero::* step_r)() { &step_right };

	// шаг назад
	void step_back() { y -= 1; }
	void (Hero::* step_b)() { &step_back };

	// шаг влево
	void step_left() { x -= 1; }
	void (Hero::* step_l)() { &step_left };

	// поворот вправо
	void turn_right();

	// поворот влево
	void turn_left();

};

class Weapon
{
public:
	virtual void use() = 0;

};

class Knife :public Weapon
{
public:
	void use() override
	{

	}
};

class Gun :public Weapon
{
public:
	void use() override
	{

	}
};

class Armor
{
public:
	virtual void wear() = 0;
	virtual void take_off() = 0;
};

class Helmet :public Armor
{
public:
	void wear() override
	{
		armor += 1; // св дальше реализация будет сложнее
	}

	void take_off() override
	{
		armor -= 1;
	}
};

class Bulletproof_vest :public Armor
{
public:
	void wear() override
	{
		armor += 1; 
	}

	void take_off() override
	{
		armor -= 1; 
	}
};

// добавление элемента и проверка на его наличие
multiset <string> ::iterator Hero::it(string thing)
{
	multiset <string> ::iterator it_thing;
	it_thing = inventory.find(thing);
	inventory.insert(thing);
	return it_thing;
}

void Hero::show_armor()
{
	// cout << armor << endl;
}

void Hero::use_weapon(Weapon &weap)
{
	weap->use();
}

// регенерация
inline void Hero::healing_poison()
{
	if (count_healing_poison > 0)
	{
		count_healing_poison--;
	}
	user.health = max(user.max_health, user.health + num_recovery_units_poison);
}

// поворот вправо
void Hero::turn_right()
{
	void (Hero:: * tmp_ptr)() {};
	tmp_ptr = step_f;

	step_f = step_r;
	step_r = step_b;
	step_b = step_l;
	step_l = tmp_ptr;
}

// поворот влево
void Hero::turn_left()
{
	void (Hero:: * tmp_ptr)() {};
	tmp_ptr = step_f;

	step_f = step_l;
	step_l = step_b;
	step_b = step_r;
	step_r = tmp_ptr;
}

//вспомогательная структура для отмотки ходов
struct hero_and_mark { 
	hero user;
	int mark;
};