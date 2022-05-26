#ifndef _HERO_H_
#define _HERO_H_

#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include "inventory.h"
#include "person.h" 
using namespace std;

// �����
class Hero
{
private:
	int x, y;	// ���������� ����� �� ����
	int direction_gaze; // ����������� �������
	int count_healing_poison; // ���������� ����� 
	int num_recovery_units_poison; // ���������� ������������� HP
	person user;
	Inventory inventory_user;
	//��������� �� �������
	typedef bool (Hero::* func_ptr)(void);

public:
	Hero();

	// ������������� ����� 
	void healing_poison();

	// ����� ������������� �����
	void show_characteristics();

	// ��� ����� 
	bool step_forward() 
	{

		y += 1; 
		return 1;
	}
	bool (Hero::* step_f)() { &Hero::step_forward };
	void call_step_f() { (this->*step_f)(); }

	// ��� ������ 
	bool step_right() 
	{ 
		x += 1;
		return 1;
	}
	bool (Hero::* step_r)() { &Hero::step_right };
	void call_step_r() { (this->*step_r)(); }

	// ��� ����� 
	bool step_back() 
	{ 
		y -= 1;
		return 1;
	}
	bool (Hero::* step_b)() { &Hero::step_back };
	void call_step_b() { (this->*step_b)(); }

	// ��� ����� 
	bool step_left() 
	{ 
		x -= 1;
		return 1;
	}
	bool (Hero::* step_l)() { &Hero::step_left };
	void call_step_l() { (this->*step_l)(); }

	// ������� ������ (��������������� ������)
	void turn_right();

	// ������� ����� (��������������� ������)
	void turn_left();

};

#endif // _HERO_H_