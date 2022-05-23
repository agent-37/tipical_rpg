#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include "inventory.h"
#include "person.h" 
using namespace std;

// указатель на функцию  
// typedef void (Hero::* func_ptr)();

// герой
class Hero
{
private:
	int x, y;	// координаты героя на поле
	int direction_gaze; // направление взгляда
	int count_healing_poison; // количество зелья 
	int num_recovery_units_poison; // количество восполняемого HP
	person user;	

public:

	// использование зелья 
	void healing_poison();

	// показ характеристик героя
	void show_characteristics();

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
