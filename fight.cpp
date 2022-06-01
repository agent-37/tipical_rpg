#include <iostream>
#include <typeinfo>
#include "fight.h"
#include "person.h"
#include "Hero.h"
#include "monsters.h"
using namespace std;

// �������� ����� �����
void hero_punch_variants(Hero& _hero, person& _monster) {
	int num, temp;
	cout << "�������� ������:" << '\n';
	cout << "1. ������: ����� ������ � ������� �����, ���� ������ ������������ �������� �� ���� ���������." << '\n';
	cout << "2. ����������" << '\n';
	cout << "3. �������: ����� ������ � ������� �����, �� ����� ��������, �.�. �� �������� ��������." << '\n';
	cout << "������� ����� �����: ";
	cin >> num;
	switch (num) {
	case 1: // ���� ����� (�� ����� 1 �����) -100, �������� +10
		temp = _hero.damage;
		_hero.damage -= 100;
		_monster.take_damage(_hero.deal_damage());
		_hero.damage = temp;
		if (_hero.health + 10 <= _hero.max_health)
			_hero.health += 10;
		else
			_hero.health = _hero.max_health;
		break;
	case 2:
		_monster.take_damage(_hero.deal_damage());
		break;
	case 3: // ���� ����� (�� ����� 1 �����) +100, ����� -50
		temp = _hero.damage;
		_hero.damage += 100;
		_monster.take_damage(_hero.deal_damage());
		_hero.damage = temp;
		_hero.armor -= 50;
		break;
	default:
		cout << "������ ����� ���. �������� ���� �� ��������������� ���������, ����������." << '\n';
		break;
	}
}

// ��� � ��������
void fight(Hero& _hero, person& _monster, int mark) {
	Hero temp_hero = _hero; // ���������� �������������� ����� �� ������ ���
	int hero_count = 0; // ���-�� ������ �����
	while (!_hero.check_died() && !_monster.check_died()) {
		if (typeid(_monster) != typeid(ghost))
			hero_punch_variants(_hero, _monster);
		hero_count++;
		// ���� ������ - ���
		if (typeid(_monster) == typeid(ogre)) {
			if (hero_count % 2 == 0)
				//dynamic_cast<ogre*>(&_monster)->regeneration();
				static_cast<ogre*>(&_monster)->regeneration();
			if (hero_count % 5 == 0)
				static_cast<ogre*>(&_monster)->heavy_blow(_hero);
			else
				_hero.take_damage(_monster.deal_damage());
		}
		// ���� ������ - ������
		else if (typeid(_monster) == typeid(skeleton)) {
			if (hero_count % 4 == 0)
				static_cast<skeleton*>(&_monster)->cursed_arrows(_hero);
			else
				_hero.take_damage(_monster.deal_damage());
		}
		// ���� ������ - �������
		else if (typeid(_monster) == typeid(ghost)) {
			if (static_cast<ghost*>(&_monster)->invisibility())
				cout << "������� ���� ���������, �� ���� ���������� �������." << '\n';
			else
				hero_punch_variants(_hero, _monster);
			if (hero_count % 3 == 0)
				static_cast<ghost*>(&_monster)->steal_gold(_hero);
			_hero.take_damage(_monster.deal_damage());
		}
		// ���� ������ - ������
		else if (typeid(_monster) == typeid(dragon)) {
			static_cast<dragon*>(&_monster)->rage(_hero);
			if (hero_count % 6 == 0)
				static_cast<dragon*>(&_monster)->heavy_blow(_hero);
			if (hero_count % 10 == 0)
				static_cast<dragon*>(&_monster)->flight();
			_hero.take_damage(_monster.deal_damage());
		}
	}
	if (_hero.check_died()) { // ����� ����
		int num;
		cout << "��� �����. �������� ���������� ��������:" << '\n';
		cout << "1. �������� ���" << '\n';
		cout << "2. ����������� ��� ���" << '\n';
		cout << "������� ����� ��������: ";
		cin >> num;
		_hero = temp_hero;
		if (num == 1)
			return;
		else if (num == 2)
			fight(_hero, _monster, mark);
		else
			cout << "������ �������� ���. �������� ���� �� ������������� ������, ����������." << '\n';
	}
	else { // ������ ����
		cout << "����������� � �������! �� ������ ������� ������ ����." << '\n';
		_hero.gold += _monster.gold;
		return;
	}
}