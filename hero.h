#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include "inventory.h"
#include "person.h" 
using namespace std;

// герой
class Hero
{
private:
	int x, y;	// координаты героя на поле
	int direction_gaze; // направление взгляда
	int count_healing_poison; // количество зелья 
	int num_recovery_units_poison; // количество восполняемого HP
	person user;
	Inventory inventory_user;
	//указатель на функцию
	typedef void (Hero::* func_ptr)(void);

public:
	Hero();

	// использование зелья 
	void healing_poison();

	// показ характеристик героя
	void show_characteristics();

	// шаг вперёд 
	void step_forward() { y += 1; }
	void (Hero::* step_f)() { &Hero::step_forward };
	void call_step_f() { (this->*step_f)(); }

	// шаг вправо 
	void step_right() { x += 1; }
	void (Hero::* step_r)() { &Hero::step_right };
	void call_step_r() { (this->*step_r)(); }

	// шаг назад 
	void step_back() { y -= 1; }
	void (Hero::* step_b)() { &Hero::step_back };
	void call_step_b() { (this->*step_b)(); }

	// шаг влево 
	void step_left() { x -= 1; }
	void (Hero::* step_l)() { &Hero::step_left };
	void call_step_l() { (this->*step_l)(); }

	// поворот вправо (переопределение клавиш)
	void turn_right();

	// поворот влево (переопределение клавиш)
	void turn_left();

};

