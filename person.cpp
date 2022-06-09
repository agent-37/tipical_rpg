#include "person.h"
#include <string>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
//��������� ������ �������������� ����-��
void person::set_person(int _health, int _damage, int _armor, int _max_health, int _gold, int _hit_chance, string _file_name) {
	health = _health;
	damage = _damage;
	armor = _armor;
	max_health = _max_health;
	gold = _gold;
	hit_chance = _hit_chance;
	file_name = _file_name;
}

//������� ��������� �����
void person::take_damage(int damage) {
	health -= max(damage - max(armor, 0), 0);
}

//��������, ��� �������� ����
int person::check_died() {
	if (health <= 0)
		return 1;
	return 0;
}

//������� ��������� �����(� ������ �������), ����� ��������� ��� �������� rand()
int person::deal_damage() {
	srand(time(NULL));
	int try_hit = rand() % 100;
	if (try_hit <= max(hit_chance, 0))
		return max(damage, 0);
	return 0;
}