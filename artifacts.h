#ifndef _ARTIFACTS_H_
#define _ARTIFACTS_H_
#include "monsters.h"
#include "Hero.h"

class artifacts {
public:
	artifacts() {};
	// Использование артефакта
	virtual void use(Hero&) {};
	// Прекращение использования артефакта (нет у potion)
	virtual void stop_use(Hero&) {};
	~artifacts() {};
};

// armor ++
class ring : public artifacts {
private:
	int value = 200; 
public:
	ring() {};
	void use(Hero& _hero) { _hero.armor += value; }
	void stop_use(Hero& _hero) { _hero.armor -= value; }
	~ring() {};
};

// max_health ++, health ++
class scroll : public artifacts { // Свиток
private:
	int value = 800;
public:
	scroll() {};
	void use(Hero& _hero);
	void stop_use(Hero& _hero);
	~scroll() {};
};

// health ++ 
class potion: public artifacts {
private:
	// Зелья хватает на 3 применения
	int count = 3;
	int value = 200;
public:
	potion() {};
	void use(Hero& _hero);
	~potion() {};
};

// hit_chance ++
class medallion : public artifacts {
private:
	int value = 50; 
public:
	medallion() {};
	void use(Hero& _hero) { _hero.hit_chance += value; }
	void stop_use(Hero& _hero) { _hero.hit_chance -= value; }
	~medallion() {};
};

// damage ++, armor --
class seal : public artifacts { // Печать
private:
	int value_damage = 300;
	int value_armor = 20;
	int diff_armor = 0;
	bool check = false;
public:
	seal() {};
	void use(Hero& _hero);
	void stop_use(Hero& _hero);
	~seal() {};
};

#endif // _ARTIFACTS_H_