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

// шаг вперёд
bool Hero::step_forward()
{
	if (y + 1 >= size_field && field_array[x][y + 1] == 1 && field_array[x][y + 1] == 2)
		return 0;
	else
	{
		y += 1;
		return 1;
	}
}

// шаг вправо 
bool Hero::step_right()
{
	if (x + 1 >= size_field && field_array[x + 1][y] == 1 && field_array[x + 1][y] == 2)
		return 0;
	else
	{
		x += 1;
		return 1;
	}
}

// шаг назад
bool Hero::step_back()
{
	if (y - 1 < 0 && field_array[x][y - 1] == 1 && field_array[x][y - 1] == 2)
		return 0;
	else
	{
		y -= 1;
		return 1;
	}
}

// шаг влево
bool Hero::step_left()
{
	if (x - 1 < 0 && field_array[x - 1][y] == 1 && field_array[x - 1][y] == 2)
		return 0;
	else
	{
		x -= 1;
		return 1;
	}
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
	func_ptr tmp_ptr();
	tmp_ptr = step_f;

	step_f = step_l;
	step_l = step_b;
	step_b = step_r;
	step_r = tmp_ptr;
}

// срубить дерево, стоящее на пути
void Hero::cut_tree()
{
	if (step_f == &step_forward && field_array[y + 1][x] == 3)
	{
		field_array[y + 1][x] = 0;
		user.gold++;
	}
	else if (step_f == &step_left && field_array[y][x - 1] == 3)
	{
		field_array[y][x - 1] = 0;
		user.gold++;
	}
	else if (step_f == &step_right && field_array[y][x + 1] == 3)
	{
		field_array[y][x + 1] = 0;
		user.gold++;
	}
	else if (step_f == &step_back && field_array[y - 1][x] == 3)
	{
		field_array[y - 1][x] = 0;
		user.gold++;
	}
}

void Hero::take_gold()
{

	if (step_f == &step_forward && field_array[y + 1][x] == 2)
		field_array[y + 1][x] = 0;
	else if (step_f == &step_left && field_array[y][x - 1] == 2)
		field_array[y][x - 1] = 0;
	else if (step_f == &step_right && field_array[y][x + 1] == 2)
		field_array[y][x + 1] = 0;
	else if (step_f == &step_back && field_array[y - 1][x] == 2)
		field_array[y - 1][x] = 0;
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

// получить размер поля
int Hero::get_size_field()
{
	return size_field;
}

int Hero::get_direction_gaze()
{
	return direction_gaze;
}

int Hero::contents_cell(int i, int j)
{
	return field_array[i][j];
}
ы
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