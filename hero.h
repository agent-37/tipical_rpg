#ifndef _HERO_H_
#define _HERO_H_

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
	int x, y;	// координаты положения героя
	int direction_gaze; // направление взгляда
	int count_healing_poison; // количество зелья
	int num_recovery_units_poison; // количество восполняемого HP
	person user;
	Inventory inventory_user;
	// указатель на функцию класса
	typedef bool (Hero::* func_ptr)(void);

public:
	Hero();

	// восполнение здоровья 
	void healing_poison();

	// показ характеристик героя
	void show_characteristics();

	// шаг вперёд
	bool step_forward()
	{
		if (  ((x == 40) && ((y) >= 50)) || // вертикальная каменная стена
			  ((y == 30) && (x < 11)) || ((y == 32) && (x < 11)) ||  // горизонтальный туннель
			  ((y == 11) && (x > 45))  ) // горизонтальная стена
			return 0;
		else
		{
			y += 1;
			return 1;
		}
	}
	bool (Hero::* step_f)() { &Hero::step_forward };
	void call_step_f() { (this->*step_f)(); }

	// шаг вправо 
	bool step_right()
	{
		if (  ((y == 12) && (x >= 45)) ||
			(x == 39) && (y > 50)  )
			return 0;
		else
		{
			x += 1;
			return 1;
		}
	}
	bool (Hero::* step_r)() { &Hero::step_right };
	void call_step_r() { (this->*step_r)(); }

	// шаг назад
	bool step_back()
	{
		if (  ((y == 13) && (x > 45)) ||
			((y == 32) && (x < 11)) || ((y == 34) && (x < 11))  )
			return 0;
		else
		{
			y -= 1;
			return 1;
		}
	}
	bool (Hero::* step_b)() { &Hero::step_back };
	void call_step_b() { (this->*step_b)(); }

	// шаг влево
	bool step_left()
	{
		if (  ((x == 41) && (y > 50)) ||
			  ((y == 33) && (x <= 11)) || ((y == 31) && (x <= 11))) )
			return 0;
		else
		{
			x -= 1;
			return 1;
		}
	}
	bool (Hero::* step_l)() { &Hero::step_left };
	void call_step_l() { (this->*step_l)(); }

	// поворот вправо 
	void turn_right();

	// поворот влево 
	void turn_left();

};

#endif // _HERO_H_