#ifndef _MONSTERS_H_
#define _MONSTERS_H_
#include "person.h"
#include "Hero.h"

// Класс огра
class ogre : public person {
public:
	ogre() { set_person(1000, 300, 200, 1000, 150, 50, "ogre.bmp"); }
	// Регенереция огра
	void regeneration();
	// Ослабление брони героя
	void heavy_blow(Hero&);
	~ogre() {}
};

// Класс скелета
class skeleton : public person {
public:
	skeleton() { set_person(500, 200, 50, 500, 150, 30, "skeleton.bmp"); }
	// Проклятые стрелы понижают обычное и максимальное здоровье героя
	void cursed_arrows(Hero&);
	~skeleton() {}
};



// Класс призрака
class ghost : public person {
public:
	ghost() { set_person(500, 200, 50, 500, 150, 30, "ghost.bmp"); }
	// Возможность призрака пропустить удар
	bool invisibility();
	// Кража золота героя
	void steal_gold(Hero&);
	~ghost() {}
};

// Класс дракона (босса)
class dragon : public person {
public:
	dragon() { set_person(2000, 500, 500, 2000, 3000, 60, "dragon.bmp"); }
	// Ослабление брони героя
	friend void ogre::heavy_blow(Hero&);
	// Эффект возгорания - каждые 1.5 секунды герой получает урон от огня (всего 4 удара)
	void decomposition(Hero&);
	// Повышение урона дракона
	void rage(Hero& _hero) { if (_hero.get_gold() >= gold) damage += 200; }
	// Дракон взлетает - затруднение попадания в него
	void flight() { hit_chance = 30; }
	~dragon() {}
};

#endif // _MONSTERS_H_