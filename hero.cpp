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
	// 4 - монстр orge
	// 5 - монстр skeleton
	// 6 - монстр ghost
	// 7 - монстр dragon

	/*x = 1;
	y = 1;*/
	x = 10;
	y = 10;
	direction_gaze = 1;
	count_healing_poison = 0;
	num_recovery_units_poison = 100;
	set_person(1000, 100, 250, 1000, 50, 50, "hero.bmp");

}

Hero::~Hero()
{

}

// восполнение здоровья
void Hero::healing_poison()
{
	if (count_healing_poison > 0)
	{
		count_healing_poison--;
		health = max(max_health, health + num_recovery_units_poison);
	}

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
	cout << "Здоровье: " << health << endl;
	cout << "Урон: " << damage << endl;
	cout << "Уровень брони героя: " << armor << endl;
	cout << "Максимальное здоровье: " << max_health << endl;
	cout << "Золото: " << gold << endl;
	cout << "Шанс попадания: " << hit_chance << endl;
	//SetConsoleCP(866);
}

// шаг вперёд
bool Hero::step_forward()
{
	y += 1;
	return 1;
}

// шаг вправо 
bool Hero::step_right()
{
	x += 1;
	return 1;
}

// шаг назад
bool Hero::step_back()
{
	y -= 1;
	return 1;
}

// шаг влево
bool Hero::step_left()
{
	x -= 1;
	return 1;
}

// получить направление взгляда
int Hero::get_direction_gaze()
{
	return direction_gaze;
}

// передать х
void Hero::set_x(int x)
{
	this->x = x;
}

// передать у
void Hero::set_y(int y)
{
	this->y = y;
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

// поворот вправо 
void Hero::turn_right()
{
	func_ptr tmp_ptr;
	tmp_ptr = step_f;

	step_f = step_r;
	step_r = step_b;
	step_b = step_l;
	step_l = tmp_ptr;
	direction_gaze = (direction_gaze + 1) % 4;
	if (direction_gaze == 0)
		direction_gaze = 4;
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
	direction_gaze = (direction_gaze + 3) % 4;
	if (direction_gaze == 0)
		direction_gaze = 4;
}

// получить  максимальное хп
int Hero::get_max_health() {
	return max_health;
}

// получить нынешнее здоровье
int Hero::get_health() {
	return health;
}
//получить золото
int Hero::get_gold() {
	return gold;
}
// передать новую броню
void Hero::set_armor(int x) {
	armor = x;
}

// передать max_health
void Hero::set_max_health(int x) {
	max_health = x;
}
// получить  броню
int Hero::get_armor() {
	return armor;
}

Hero& Hero::operator = (Hero _user) {
	Hero help;
	x = _user.get_x();
	y = _user.get_y();
	direction_gaze = _user.get_direction_gaze();
	count_healing_poison = _user.get_count_healing_poison();
	num_recovery_units_poison = _user.get_num_recovery_units_poison();
	inventory_user = _user.get_inventory_user();
	health = _user.health;
	damage = _user.damage;
	armor = _user.armor;
	max_health = _user.max_health;
	gold = _user.gold;
	hit_chance = _user.hit_chance;
	file_name = _user.file_name;
	return *this;
}
void Hero::set_inventory_user(Inventory _inventory_user) {
	inventory_user = _inventory_user;
}
int  Hero::get_count_healing_poison() {
	return count_healing_poison;
}
void  Hero::set_direction_gaze(int _direction_gaze) {
	direction_gaze = _direction_gaze;
}
void  Hero::set_count_healing_poison(int _count_healing_poison) {
	count_healing_poison = _count_healing_poison;
}
void  Hero::set_num_recovery_units_poison(int _num_recovery_units_poison) {
	num_recovery_units_poison = _num_recovery_units_poison;
}

int  Hero::get_num_recovery_units_poison() {
	return num_recovery_units_poison;
}
Inventory Hero::get_inventory_user() {
	return inventory_user;
}