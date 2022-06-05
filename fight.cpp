#include <iostream>
#include <typeinfo>
#include "fight.h"
#include "person.h"
#include "Hero.h"
#include "monsters.h"
using namespace std;

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
void fight(Hero& _hero, person& _monster) {
	Hero temp_hero = _hero; // Запоминаем характеристики героя до начала боя
	int hero_count = 0; // Кол-во ударов героя
	while (!_hero.check_died() && !_monster.check_died()) {
		if (typeid(_monster) != typeid(ghost))
			hero_punch_variants(_hero, _monster);
		hero_count++;
		// Если монстр - огр
		if (typeid(_monster) == typeid(ogre)) {
			if (hero_count % 2 == 0)
				//dynamic_cast<ogre*>(&_monster)->regeneration();
				static_cast<ogre*>(&_monster)->regeneration();
			if (hero_count % 5 == 0)
				static_cast<ogre*>(&_monster)->heavy_blow(_hero);
			else
				_hero.take_damage(_monster.deal_damage());
		}
		// Если монстр - скелет
		else if (typeid(_monster) == typeid(skeleton)) {
			if (hero_count % 4 == 0)
				static_cast<skeleton*>(&_monster)->cursed_arrows(_hero);
			else
				_hero.take_damage(_monster.deal_damage());
		}
		// Если монстр - призрак
		else if (typeid(_monster) == typeid(ghost)) {
			if (static_cast<ghost*>(&_monster)->invisibility())
				cout << "Призрак стал невидимым, по нему невозможно ударить." << '\n';
			else
				hero_punch_variants(_hero, _monster);
			if (hero_count % 3 == 0)
				static_cast<ghost*>(&_monster)->steal_gold(_hero);
			_hero.take_damage(_monster.deal_damage());
		}
		// Если монстр - дракон
		else if (typeid(_monster) == typeid(dragon)) {
			static_cast<dragon*>(&_monster)->rage(_hero);
			if (hero_count % 6 == 0)
				static_cast<dragon*>(&_monster)->heavy_blow(_hero);
			if (hero_count % 10 == 0)
				static_cast<dragon*>(&_monster)->flight();
			_hero.take_damage(_monster.deal_damage());
		}
	}
	if (_hero.check_died()) { // Герой умер
		int num;
		cout << "Вас убили. Варианты дальнейших действий:" << '\n';
		cout << "1. Покинуть бой" << '\n';
		cout << "2. Попробовать еще раз" << '\n';
		cout << "Введите номер варианта: ";
		cin >> num;
		_hero = temp_hero;
		if (num == 1)
			return;
		else if (num == 2)
			fight(_hero, _monster);
		else
			cout << "Такого варианта нет. Выберите один из предложенного списка, пожалуйста." << '\n';
	}
	else { // Монстр умер
		cout << "Поздравляем с победой! Всё золото монстра теперь ваше." << '\n';
		_hero.gold += _monster.gold;
		return;
	}
}