#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include "inventory.h"
#include "person.h" 
using namespace std;

// указатель на функцию  
// typedef void (Hero::* func_ptr)();

// герой
class Hero
{
private:
	int x, y;	// координаты героя на поле
	int direction_gaze; // направление взгляда
	int armor; // броня"
	int count_healing_poison; // количество зелья 
	int num_recovery_units_poison; // количество восполняемого HP
	person user;

public:

	// использование зелья 
	void healing_poison();

	// показ характеристик героя
	void show_characteristics();

	// шаг вперёд 
	void step_forward() { y += 1; }
	void (Hero::* step_f)() { &Hero::step_forward };

	// шаг вправо 
	void step_right() { x += 1; }
	void (Hero::* step_r)() { &Hero::step_right };

	// шаг назад 
	void step_back() { y -= 1; }
	void (Hero::* step_b)() { &Hero::step_back };

	// шаг влево 
	void step_left() { x -= 1; }
	void (Hero::* step_l)() { &Hero::step_left };

	// поворот вправо 
	void turn_right();

	// поворот влево 
	void turn_left();

};

// восполнение здоровья
inline void Hero::healing_poison()
{
	if (count_healing_poison > 0)
	{
		count_healing_poison--;
	}
	user.health = max(user.max_health, user.health +
		num_recovery_units_poison);
}

// показ характеристик героя
void Hero::show_characteristics()
{
	// SetlocaleCP(1251);
	cout << "Координаты героя: " << "x = " << x << ", y = " << y << ";" << endl;
	cout << "Количество зелья: " << count_healing_poison << endl;
	cout << "Количество восполянемого HP: " << num_recovery_units_poison << endl;
	cout << "Надетые атифакты: " << endl;
	// object.show_weared_artifacts(); // объект инвенторя, показ надетых артифактов
	cout << "Направление взгляда: " << direction_gaze;
	cout << "Здоровье: " << user.health << endl;
	cout << "Урон: " << user.damage << endl;
	cout << "Уровень брони героя: " << user.armor << endl;
	cout << "Максимальное здоровье: " << user.max_health << endl;
	cout << "Золото: " << user.gold << endl;
	cout << "Шанс попадания: " << user.hit_chance << endl;
	// SetlocaleCP(866);
}

// поворот вправо 
void Hero::turn_right()
{
	void (Hero:: * tmp_ptr)() {};
	tmp_ptr = step_f;

	step_f = step_r;
	step_r = step_b;
	step_b = step_l;
	step_l = tmp_ptr;
}

// поворот влево 
void Hero::turn_left()
{
	void (Hero:: * tmp_ptr)() {};
	tmp_ptr = step_f;

	step_f = step_l;
	step_l = step_b;
	step_b = step_r;
	step_r = tmp_ptr;
}

//вспомогательная структура для отмотки ходов 
struct hero_and_mark
{
	Hero user;
	int mark;
};
