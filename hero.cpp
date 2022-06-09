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

	x = 10;
	y = 10;
	direction_gaze = 1;
	count_healing_poison = 0;
	num_recovery_units_poison = 100;
	set_person(1000, 100, 100, 1000, 50000, 50, "hero.bmp");

}

Hero::~Hero()
{

}

// восполнение здоровья
int Hero::healing_poison()
{
	if (count_healing_poison > 0)
	{
		count_healing_poison--;
		health = max(max_health, health + num_recovery_units_poison);
		return 1;
	}
	return 0;

}

// показ характеристик героя
void Hero::show_characteristics()
{
	setlocale(LC_ALL, "rus");
	cout << "Координаты героя: " << "x = " << x << ", y = " << y << ";" << endl;
	cout << "Количество зелья: " << count_healing_poison << endl;
	cout << "Количество восполянемого HP: " << num_recovery_units_poison << endl;
	cout << "Направление взгляда: " << direction_gaze << endl;
	cout << "Здоровье: " << health << endl;
	cout << "Урон: " << max(0, damage) << endl;
	cout << "Уровень брони героя: " << max(0, armor) << endl;
	cout << "Максимальное здоровье: " << max_health << endl;
	cout << "Золото: " << gold << endl;
	cout << "Шанс попадания: " << min(max(0, hit_chance), 100) << endl;
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
	return max(armor, 0);
}

//переопределение оператора =
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

//передать инвентарь
void Hero::set_inventory_user(Inventory _inventory_user) {
	inventory_user = _inventory_user;
}

//получить количество зелий здоровья
int  Hero::get_count_healing_poison() {
	return count_healing_poison;
}

//передать направление взляда
void  Hero::set_direction_gaze(int _direction_gaze) {
	direction_gaze = _direction_gaze;
}

//передать количество зелий здоровья
void  Hero::set_count_healing_poison(int _count_healing_poison) {
	count_healing_poison = _count_healing_poison;
}

//передать количество хп на которое восполняет зелье здоровья
void  Hero::set_num_recovery_units_poison(int _num_recovery_units_poison) {
	num_recovery_units_poison = _num_recovery_units_poison;
}

//получить количество хп на которое восполняет зелье здоровья
int  Hero::get_num_recovery_units_poison() {
	return num_recovery_units_poison;
}

//получить инвентарь
Inventory Hero::get_inventory_user() {
	return inventory_user;
}

//добавить артифакт в рюкзак
void Hero::add_artifact(string art) {
	inventory_user.not_weared_inventory.insert(art);
}

//передать золото
void Hero::set_gold(int _gold) {
	gold = _gold;
}

//показать все артефакты в рюкзаке
void Hero::show_un_wear_art()
{
	inventory_user.it_not_weared = inventory_user.not_weared_inventory.begin();
	while (inventory_user.it_not_weared != inventory_user.not_weared_inventory.end()) {
		cout << *inventory_user.it_not_weared << endl;
		inventory_user.it_not_weared++;
	}

}

//показать все надетые артефакты
void Hero::show_wear_art() {

	inventory_user.it_weared = inventory_user.weared_inventory.begin();
	while (inventory_user.it_weared != inventory_user.weared_inventory.end()) {
		cout << *inventory_user.it_weared << endl;
		inventory_user.it_weared++;
	}
}

//добавить зелье здоровья
void Hero::add_potion()
{
	count_healing_poison++;
}

//снять артефакт
int Hero::un_wear_art(string art) {
	if (inventory_user.weared_inventory.find(art) == inventory_user.weared_inventory.end())
		return 0;
	if (art == "ring_of_power")
		damage -= 5;
	else if (art == "amulet_of_health") {
		max_health -= 50;
		health = max(health, max_health);
	}
	else if (art == "pendant_of_dispassion") {
		max_health += 40;
		damage -= 30;
	}
	else if (art == "cursed_ring") {
		max_health += 40;
		damage -= 30;
		armor += 15;
	}
	else if (art == "victory_necklace") {
		damage -= 10;
		max_health -= 50;
		health = max(health, max_health);
	}
	else if (art == "armadillo_pendant")
		armor -= 20;
	else if (art == "clover_of_fortune")
		hit_chance -= 5;
	else if (art == "ring_of_sinners") {
		max_health += 60;
		damage -= 30;
		hit_chance -= 5;
		armor += 35;
	}
	else if (art == "lightning_rune")
		damage -= 15;
	else if (art == "necklace_of_dragonteeth") {
		armor -= 30;
		max_health -= 50;
		health = max(health, max_health);
	}
	else if (art == "flame_rune")
		damage -= 20;
	else if (art == "speed_ring") {
		damage -= 10;
		armor += 20;
	}
	else if (art == "pendant_of_skill") {
		damage -= 20;
		max_health -= 50;
		health = max(health, max_health);
		armor -= 10;
	}
	else if (art == "regeneration_ring")
		num_recovery_units_poison -= 50;
	else if (art == "sar-issa_ring") {
		damage -= 70;
		max_health -= 150;
		health = max(health, max_health);
		hit_chance -= 5;
	}
	inventory_user.weared_inventory.erase(inventory_user.weared_inventory.find(art));
	inventory_user.not_weared_inventory.insert(art);
	return 1;
}

//надеть артефакт	
int Hero::wear_art(string art) {
	if (inventory_user.not_weared_inventory.find(art) == inventory_user.not_weared_inventory.end())
		return 0;
	if (art == "ring_of_power")
		damage += 5;
	else if (art == "amulet_of_health")
		max_health += 50;
	else if (art == "pendant_of_dispassion") {
		max_health -= 40;
		health = max(health, max_health);
		damage += 30;
	}
	else if (art == "cursed_ring") {
		max_health -= 40;
		health = max(health, max_health);
		damage += 30;
		armor -= 15;
	}
	else if (art == "victory_necklace") {
		damage += 10;
		max_health += 50;
	}
	else if (art == "armadillo_pendant")
		armor += 20;
	else if (art == "clover_of_fortune")
		hit_chance += 5;
	else if (art == "ring_of_sinners") {
		max_health -= 60;
		health = max(health, max_health);
		damage += 30;
		hit_chance += 5;
		armor -= 35;
	}
	else if (art == "lightning_rune")
		damage += 15;
	else if (art == "necklace_of_dragonteeth") {
		armor += 30;
		max_health += 50;
	}
	else if (art == "flame_rune")
		damage += 20;
	else if (art == "speed_ring") {
		damage += 10;
		armor -= 20;
	}
	else if (art == "pendant_of_skill") {
		damage += 20;
		max_health += 50;
		armor += 10;
	}
	else if (art == "regeneration_ring")
		num_recovery_units_poison += 50;
	else if (art == "sar-issa_ring") {
		damage += 70;
		max_health += 150;
		hit_chance += 5;
	}
	inventory_user.not_weared_inventory.erase(inventory_user.not_weared_inventory.find(art));
	inventory_user.weared_inventory.insert(art);

	return 1;

}