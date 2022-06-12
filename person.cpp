#include "person.h"
#include <string>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
//процедура задает характеристики кому-то
void person::set_person(int _health, int _damage, int _armor, int _max_health, int _gold, int _hit_chance, string _file_name) {
	health = _health;
	damage = _damage;
	armor = _armor;
	max_health = _max_health;
	gold = _gold;
	hit_chance = _hit_chance;
	file_name = _file_name;
}

//функция получения урона
void person::take_damage(int damage) {
	health -= max(damage - max(armor, 0), 0);
}

//проверка, что персонаж умер
int person::check_died() {
	if (health <= 0)
		return 1;
	return 0;
}

//функция нанесения урона(с учетом промоха), НУЖНО ПРОВЕРИТЬ ЧТО РАБОТАЕТ rand()
int person::deal_damage() {
	srand(time(NULL));
	int try_hit = rand() % 100;
	if (try_hit <= max(hit_chance, 0))
		return max(damage, 0);
	return 0;
}