#include "monsters.h"
#include "Hero.h"
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

// ќслабление брони геро€
void help::heavy_blow(Hero& _hero) {
	_hero.armor -= 50;
	_hero.take_damage(deal_damage());
}

// –егенереци€ огра
void ogre::regeneration() {
	int num_of_regeneration = 10;
	if (health + num_of_regeneration <= max_health)
		health += num_of_regeneration;
	else
		health = max_health;
}

// ѕрокл€тые стрелы понижают обычное и максимальное здоровье геро€
void skeleton::cursed_arrows(Hero& _hero) {
		_hero.take_damage(deal_damage());
		if (!_hero.check_died())
			_hero.max_health -= damage;
}

// ¬озможность призрака пропустить удар
bool ghost::invisibility() {
	// –андомно выбираем 0 или 1 - шанс того, что призрак пропустит удар
	srand(time(NULL));
	int chance = rand() % 2;
	if (chance == 1)
		return 1;
	return 0;
}

//  ража золота геро€
void ghost::steal_gold(Hero& _hero) {
	int num_of_stealing = 50;
	if (_hero.gold - num_of_stealing >= 0)
		_hero.gold += num_of_stealing;
	else
		_hero.gold = 0;
}