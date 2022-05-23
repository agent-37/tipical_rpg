#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include "hero.h"
#include "inventory.h"
#include "person.h" 

using namespace std;

// регенерация 
inline void Hero::healing_poison()
{
	if (count_healing_poison > 0)
	{
		count_healing_poison--;
	}
	user.health = max(user.max_health, user.health +
	num_recovery_units_poison);
}

// показ характеристик героя
void Hero::show_characteristics()
{
	SetlocaleCP(1251);
	cout << "Координаты героя: " << "x = " << x << ", y = " << y << ";" << endl;
	cout << "Количество зелья: " << count_healing_poison << endl;
	cout << "Количество восполянемого HP: " << num_recovery_units_poison << endl;
	cout << "Надетые атифакты: " << endl;
	object.show_weared_artifacts(); // объект инвенторя, показ надетых артифактов
	cout << "Направление взгляда: " << direction_gaze;
	cout << "Здоровье: " << health << endl;
	cout << "Урон: " << damage << endl;
	cout << "Уровень брони героя: " << armor << endl;
	cout << "Максимальное здоровье: " << max_health << endl;
	cout << "Золото: " << gold << endl;
	cout << "Шанс попадания: " << hit_chance << endl;
	SetlocaleCP(866);
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