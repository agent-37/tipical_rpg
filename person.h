#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
using namespace std;
//класс характеристик. Необходим для создания классов монстров и класса героя
class person {
public:
	//текущее здоровье, максимальное здоровье, урон, броня, золото, шанс попадания по противнику
	int health, max_health, damage, armor, gold;
	int hit_chance;
	string file_name;
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
	void set_person(int, int, int, int, int, int,string);

	//функция получения урона
	void take_damage(int);

	//проверка, что персонаж умер
	int check_died();

	//функция нанесения урона(с учетом промоха), НУЖНО ПРОВЕРИТЬ ЧТО РАБОТАЕТ rand()
	int deal_damage();
};
#endif // _PERSON_H_
