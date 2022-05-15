#include "person.h"
#include <random>

//��������� ������ �������������� ����-��
void person::set_person(int _health, int _damage, int _armor, int _max_health, int _gold, int _hit_chance) {
	health = _health;
	damage = _damage;
	armor = _armor;
	max_health = _max_health;
	gold = _gold;
	hit_chance = _hit_chance;
}

//������� ��������� �����
void person::take_damage(int damage) {
	health -= damage;
}

//��������, ��� �������� ����
int person::check_died() {
	if (health <= 0)
		return 1;
	return 0;
}

//������� ��������� �����(� ������ �������), ����� ��������� ��� �������� rand()
int person::deal_damage() {
	int try_hit = rand() % 100;
	if (try_hit >= hit_chance)
		return damage;
	return 0;
}