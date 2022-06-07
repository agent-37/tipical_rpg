#include <iostream>
#include <typeinfo>
#include "fight.h"
#include "person.h"
#include "Hero.h"
#include "monsters.h"
#include "draw.h"
using namespace std;
enum file_monsters { empty_cell = 0, unbreakable = 1, breakable = 2, heep_gold = 3, _ogre = 4, _skeleton = 5, _ghost = 6, _dragon = 7, _trader = 8 };

// Варианты удара героя
void hero_punch_variants(Hero& _hero, person& _monster) {
	int num, temp;
	cout << "Варианты ударов:" << '\n';
	cout << "1. Слабый: герой ударит с меньшей силой, зато сможет восстановить здоровье за счет передышки." << '\n';
	cout << "2. Нормальный" << '\n';
	cout << "3. Сильный: герой ударит с большей силой, но броня ослабнет, т.к. не выдерижт нагрузки." << '\n';
	cout << "Введите номер удара: ";
	cin >> num;
	switch (num) {
	case 1: // Сила героя (на время 1 удара) -100, здоровье +10
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
	case 3: // Сила героя (на время 1 удара) +100, броня -50
		temp = _hero.damage;
		_hero.damage += 100;
		_monster.take_damage(_hero.deal_damage());
		_hero.damage = temp;
		_hero.armor -= 50;
		break;
	default:
		cout << "Такого удара нет. Выберите один из предоставленных вариантов, пожалуйста." << '\n';
		break;
	}
}

// Бой с монстром
void fight(Hero& _hero, person& _monster, int mark) {
	Hero temp_hero = _hero; // Запоминаем характеристики героя до начала боя
	int hero_count = 0; // Кол-во ударов героя
	draw_fight(_hero, _monster, mark);
	while (!_hero.check_died() && !_monster.check_died()) {
		if (mark != _ghost)
			hero_punch_variants(_hero, _monster);
		draw_fight(_hero, _monster, mark);
		hero_count++;
		// Если монстр - огр
		switch (mark) {
		case(_ogre): {
			if (hero_count % 2 == 0) {
				//dynamic_cast<ogre*>(&_monster)->regeneration();
				static_cast<ogre*>(&_monster)->regeneration();
				cout << "Огр регенерировал!" << endl;
			}
			if (hero_count % 5 == 0) {
				static_cast<ogre*>(&_monster)->heavy_blow(_hero);
				cout << "Особая атака огра! Броня героя понижена." << endl;
			}
			else
				_hero.take_damage(_monster.deal_damage());
			break;
		}
		case(_skeleton): {
			if (hero_count % 4 == 0) {
				static_cast<skeleton*>(&_monster)->cursed_arrows(_hero);
				cout << "Скелет использовал проклятые стрелы. Вы чувствуете, что от вас уходят силы!" << endl;
			}
			else
				_hero.take_damage(_monster.deal_damage());
			break;
		}
		case(_ghost): {
			if (static_cast<ghost*>(&_monster)->invisibility())
				cout << "Призрак стал невидимым, по нему невозможно ударить." << '\n';
			else
				hero_punch_variants(_hero, _monster);
			if (hero_count % 3 == 0) {
				static_cast<ghost*>(&_monster)->steal_gold(_hero);
				cout << "Ваш кошелек стал значительно легче." << endl;

			}
			_hero.take_damage(_monster.deal_damage());
			break;
		}

		case(_dragon): {static_cast<dragon*>(&_monster)->rage(_hero);
			if (hero_count % 6 == 0) {
				static_cast<dragon*>(&_monster)->heavy_blow(_hero);
				cout << "Особая атака дракона! Броня героя понижена." << endl;
			}
			if (hero_count % 10 == 0) {
				static_cast<dragon*>(&_monster)->flight();
				cout << "Дракон залез на потолок.(Как теперь его достать?)" << endl;
			}
			_hero.take_damage(_monster.deal_damage());
			break;
		}
		}
	}
	_hero.max_health = temp_hero.max_health;
	_hero.gold += _monster.gold;
	_hero.armor = temp_hero.armor;
}