#ifndef _PERSON_H_
#define _PERSON_H_
#include <random>
//класс характеристик. Необходим для создания классов монстров и класса героя
class person {
public:
	//текущее здоровье, максимальное здоровье, урон, броня, золото, шанс попадания по противнику
	int health, max_health, damage, armor, gold;
	int hit_chance;
	 person() {
		health = 0;
		damage = 0;
		armor = 0;
		max_health = 0;
		hit_chance = 0;
		gold = 0;
	}
	~person() {}
protected:
	//процедура задает характеристики кому-то
	void set_person(int _health, int _damage, int _armor, int _max_health, int _gold, int _hit_chance) {
		health = _health;
		damage = _damage;
		armor = _armor;
		max_health = _max_health;
		gold = _gold;
		hit_chance = _hit_chance;
	}
	//функция получения урона
	void take_damage(int damage) {
		health -= damage;
	}
	//проверка, что персонаж умер
	int check_died() {
		if (health <= 0)
			return 1;
		return 0;
	}
	//функция нанесения урона(с учетом промоха), НУЖНО ПРОВЕРИТЬ ЧТО РАБОТАЕТ rand()
	int deal_damage() {
		int try_hit = rand() % 100;
		if (try_hit >= hit_chance)
			return damage;
		return 0;
	}
};

#endif // _PERSON_H_
