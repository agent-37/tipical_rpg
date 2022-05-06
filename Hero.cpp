#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>

using namespace std;

class Hero
{
private:
	// координаты поля
	int x, y;
	int direction_gaze;
	multiset <string> inventory;

public:
	multiset <string> ::iterator it(string thing);
	void healing_poison(int health);
	void town_portal() { /*пока такие*/ x = 0; y = 0; }

	// шаг вперёд
	void step_forward() { y += 1; }
	void (Hero::* step_f)() { &step_forward };

	// шаг вправо
	void step_right() { x += 1; }
	void (Hero::* step_r)() { &step_right };

	// шаг назад
	void step_back() { y -= 1; }
	void (Hero::* step_b)() { &step_back };

	// шаг влево
	void step_left() { x -= 1; }
	void (Hero::* step_l)() { &step_left };

	// поворот вправо
	void turn_right();

	// поворот влево
	void turn_left();
};


int main()
{

}

// добавление элемента и проверка на его наличие
multiset <string> ::iterator Hero::it(string thing)
{
	multiset <string> ::iterator it_thing;
	it_thing = inventory.find(thing);
	inventory.insert(thing);
	return it_thing;
}

// вообще не понял чё тут надо
/// + к здоровью
///void Hero::healing_poison(int health)
///{
///	this->health += health;
///}

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