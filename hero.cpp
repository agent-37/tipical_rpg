#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include <fstream>
#include "inventory.h"
#include "person.h" 
#include "hero.h"  

using namespace std;

Hero::Hero()
{
	// 1 - камень (неубираемое препядствие)
	// 2 - дерево (убираемое препядствие)
	// 3 - золото (собирать)
	// 4 - монстры
	// 5 - orge
	// 6 - skeleton
	// 7 - ghost
	// 8 - dragon

	x = 0;
	y = 0;
	direction_gaze = 0;
	count_healing_poison = 0;
	num_recovery_units_poison = 0;

}

Hero::~Hero()
{

}

// восполнение здоровья
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
	/*SetConsoleCP(1251);*/
	setlocale(LC_ALL, "rus");
	cout << "Координаты героя: " << "x = " << x << ", y = " << y << ";" << endl;
	cout << "Количество зелья: " << count_healing_poison << endl;
	cout << "Количество восполянемого HP: " << num_recovery_units_poison << endl;
	cout << "Надетые атифакты: " << endl;
	//object.show_weared_artifacts(); // объект инвенторя, показ надетых артифактов
	cout << "Направление взгляда: " << direction_gaze << endl;
	cout << "Здоровье: " << user.health << endl;
	cout << "Урон: " << user.damage << endl;
	cout << "Уровень брони героя: " << user.armor << endl;
	cout << "Максимальное здоровье: " << user.max_health << endl;
	cout << "Золото: " << user.gold << endl;
	cout << "Шанс попадания: " << user.hit_chance << endl;
	//SetConsoleCP(866);
}

// шаг вперёд
bool Hero::step_forward()
{
	/*if (y + 1 >= field.get_size_map() && field.get_cell(x, y + 1) == 1 && field.get_cell(x, y + 1) == 2)
	return 0;
	else*/
	{
		y += 1;
		return 1;
	}
}

// шаг вправо 
bool Hero::step_right()
{
	/*if (x + 1 >= field.get_size_map() && field.get_cell(x + 1, y) == 1 && field.get_cell(x + 1, y) == 2)
	return 0;
	else*/
	{
		x += 1;
		return 1;
	}
}

// шаг назад
bool Hero::step_back()
{
	/*if (y - 1 < 0 && field.get_cell(x, y - 1) == 1 && field.get_cell(x, y - 1) == 2)
	return 0;
	else*/
	{
		y -= 1;
		return 1;
	}
}

// шаг влево
bool Hero::step_left()
{
	/*if (x - 1 < 0 && field.get_cell(x - 1, y) == 1 && field.get_cell(x - 1, y) == 2)
	return 0;
	else*/
	{
		x -= 1;
		return 1;
	}
}

int Hero::get_direction_gaze()
{
	return direction_gaze;
}

// поворот вправо 
void Hero::turn_right()
{
	func_ptr tmp_ptr;
	tmp_ptr = step_f;

	step_f = step_r;
	step_r = step_b;
	step_b = step_l;
	step_l = tmp_ptr;
}

// поворот влево 
void Hero::turn_left()
{
	func_ptr tmp_ptr;
	tmp_ptr = step_f;

	step_f = step_l;
	step_l = step_b;
	step_b = step_r;
	step_r = tmp_ptr;
}

// получить координату х героя
int Hero::get_x()
{
	return x;
}

// получить координату y героя
int Hero::get_y()
{
	return y;
}

// вспомогательная структура для отмотки ходов 
struct hero_and_mark
{
	Hero user;
	int mark;
};

