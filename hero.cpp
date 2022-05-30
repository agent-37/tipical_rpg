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

	x = 0;
	y = 0;
	direction_gaze = 0;
	count_healing_poison = 0;
	num_recovery_units_poison = 0;

	fstream fin("input.txt", fstream::in | fstream::out | fstream::app);

	fin >> size_field;

	// создание поля
	field_array = new int* [size_field];

	for (int i = 0; i < size_field; i++)
		field_array[i] = new int[size_field]{};

	// чтение поля из файла
	for (int i = 0; i < size_field; i++)
		for (int j = 0; j < size_field; j++)
			fin >> field_array[i][j];

	fin.close();
	
}

Hero::~Hero()
{
	for (int i = 0; i < size_field; i++)
	{
		delete[] field_array[i];
		field_array[i] = nullptr;
	}
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
	SetConsoleCP(1251);
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
	SetConsoleCP(866);
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

int Hero::get_size_field()
{
	return size_field;
}

// вспомогательная структура для отмотки ходов 
struct hero_and_mark
{
	Hero user;
	int mark;
};


int main()
{
	// тест
	Hero herot;
	cout << to_string(1) << " Созданный объект" << endl;
	herot.show_characteristics();

	herot.call_step_r();
	cout << to_string(2) << " Сделал шаг вправо" << endl;
	herot.show_characteristics();

	herot.turn_left();
	cout << to_string(3) << " Поворот влево, но ничего не должно измениться" << endl;
	herot.show_characteristics();

	herot.call_step_r();
	cout << to_string(4) << "Шаг вправо должен изменить другие координаты" << endl;
	herot.show_characteristics();

	system("pause");
	return 0;
}