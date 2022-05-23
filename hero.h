#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
//#include "person.h" 

using namespace std;

// указатель на функцию  
typedef void (Hero::* func_ptr)();

class Weapon;
class Hero;
class Inventory;

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

// герой
class Hero
{
private:
	// координаты поля 
	int x, y;
	int direction_gaze;
	int armor;
	int artifacts;
	int count_healing_poison;
	int num_recovery_units_poison; // позже решим, кол-во хп на сколько регенит зелье 

	//person user;

public:

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
	void using_weapon(Weapon* weap);
	void show_armor();

	// шаг вперёд 
	void step_forward() { y += 1; }
	void (Hero::* step_f)() { &Hero::step_forward };

	// шаг вправо 
	void step_right() { x += 1; }
	void (Hero::* step_r)() { &Hero::step_right };

	// шаг назад 
	void step_back() { y -= 1; }
	void (Hero::* step_b)() { &Hero::step_back };

	// шаг влево 
	void step_left() { x -= 1; }
	void (Hero::* step_l)() { &Hero::step_left };

	// поворот вправо 
	void turn_right();

	// поворот влево 
	void turn_left();

};

// оружие
class Weapon
{
public:
	virtual void use_weapon() = 0;
};

// нож
class Knife :public Weapon
{
public:
	void use_weapon() override
	{
		// уточнить реализацию ударов(применения оружия)
	}
};

// пистолет
class Gun :public Weapon
{
public:
	void use_weapon() override
	{

	}
};

// пистолет - пулемёт
class Machine_Gun :public Weapon
{
public:
	void use_weapon() override
	{

	}
};

// дубинка
class Club : public Weapon
{
public:
	void use_weapon() override
	{

	}
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

// использовать оружие
void Hero::using_weapon(Weapon* weap)
{
	weap->use_weapon();
}

// броня показыается целочисленной переменной 
void Hero::show_armor()
{
	cout << armor << endl;
}

// регенерация 
inline void Hero::healing_poison()
{
	if (count_healing_poison > 0)
	{
		count_healing_poison--;
	}
	/*user.health = max(user.max_health, user.health +
		num_recovery_units_poison);*/
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
struct hero_and_mark
{
	Hero user;
	int mark;
};