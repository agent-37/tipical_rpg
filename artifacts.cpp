#include "artifacts.h"

// max_health ++, health ++
void scroll::use(Hero& _hero) {
	_hero.max_health += value;
	_hero.health = _hero.max_health;
}

// max_health --, health --
void scroll::stop_use(Hero& _hero) {
	_hero.max_health -= value;
	if (_hero.health > _hero.max_health)
		_hero.health = _hero.max_health;
}

// health ++ 
void potion::use(Hero& _hero) {
	if (count > 0) {
		if (_hero.health + value <= _hero.max_health)
			_hero.health += value;
		else
			_hero.health = _hero.max_health;
		count--;
	}
}

// damage ++, armor --
void seal::use(Hero& _hero) {
	_hero.damage += value_damage;
	if (_hero.armor - value_armor >= 0)
		_hero.armor -= value_armor;
	else {
		check = true;
		diff_armor = value_armor - _hero.armor;
		_hero.armor = 0;
	}
}

// damage --, armor ++
void seal::stop_use(Hero& _hero) {
	_hero.damage -= value_damage;
	if (check) {
		_hero.armor += diff_armor;
		check = false;
	}
	else
		_hero.armor += value_armor;
}