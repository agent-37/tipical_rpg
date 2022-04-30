#ifndef _CHARACTERISRIC_H_
#define _CHARACTERISRIC_H_

//класс характеристик. Необходим для создания классов монстров и класса героя
class characteristic {
public:
	//текущее здоровье, максимальное здоровье, урон, броня, золото, шанс попадания по противнику
	int health, max_health, damage, armor,  gold;
	double hit_chance;
	characteristic() {
		health = 0;
		damage = 0;
		armor = 0;
		max_health = 0;
		hit_chance = 0;
		gold = 0;
	}
	~characteristic(){}
public:
	//процедура задает характеристики кому-то
	set_characteristic(int _health,int _damage,int _armor,int _max_health,int _gold, double _hit_chance;) {
		health = _health;
		damage = _damage;
		armor = _armor;
		max_health = _max_health;
		gold = _gold;
		hit_chance = _hit_chance;
	 }
};

#endif // _CHARACTERISRIC_H_