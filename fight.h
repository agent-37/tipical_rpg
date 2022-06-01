#ifndef _FIGHT_H_
#define _FIGHT_H_
#include "Hero.h"

// Варианты удара героя
void hero_punch_variants(Hero& _hero, person& _monster);

// Бой с монстром
void fight(Hero& _hero, person& monster, int mark);

#endif // _FIGHT_H_