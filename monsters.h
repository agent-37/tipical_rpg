#ifndef _MONSTERS_H_
#define _MONSTERS_H_
#include "characteristic.h" 

// Все числа в характеристиках поставлены наугад. Точные значения будут обсуждаться позднее.
// В основном здесь заготовки функций. Произошли проблемы с подключением класса героя, поэтому 
// взаимодейтсвие монстров и героя описаны примерно

// Класс всех монстров
class monster : public characteristic {
public:
	monster() {}
	void deal_damage(int damage) { /* Нанесение урона по герою */ }
	void take_damage(int hero_damage, int armor) { /* Получение урона от героя */ }
	void death() { /* Смерть монстра */ }  // Мб надо убрать, не знаю пока
	~monster() {}
};

// Класс огра
class ogre : public monster {
private:
	ogre() { set_characteristic(1000, 300, 200, 1000, 150, 0.5); }
	~ogre() {}
public:
	void regeneration() {
		int num_of_regeneration = 10;
		if (health + num_of_regeneration <= max_health)
			health += num_of_regeneration;
		else
			health = max_health;
	}
};

// Класс скелета
class skeleton : public monster {
private:
	skeleton() { set_characteristic(500, 200, 50, 500, 150, 0.3); }
	~skeleton() {}
public:
	// Пока не придумала особенностей
};

// Класс слайма
class slime : public monster {
private:
	slime() { set_characteristic(500, 200, 0, 500, 150, 0.3); }
	~slime() {}
public:
	void duplication(slime big_slime) {
		big_slime.death();
		slime small_slime1, small_slime2;
		small_slime1.set_characteristic(big_slime.health / 2, 200, 0, big_slime.max_health / 2, big_slime.gold / 2, 0.3);
		small_slime2.set_characteristic(big_slime.health / 2, 200, 0, big_slime.max_health / 2, big_slime.gold / 2, 0.3);
	}
};

// Класс дракона (босса)
class dragon : public monster {
private:
	dragon() { set_characteristic(2000, 500, 500, 2000, 3000, 0.6); }
	~dragon() {}
public:
	void spit_fire() { /* Заполняет одну ячейку(или несколько) огнем.Персонаж получит урон, если наступит на эту область */ }
};

#endif // _MONSTERS_H_