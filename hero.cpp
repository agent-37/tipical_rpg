#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include "hero.h"
#include "inventory.h"
#include "person.h" 

using namespace std;

// ����������� 
inline void Hero::healing_poison()
{
	if (count_healing_poison > 0)
	{
		count_healing_poison--;
	}
	user.health = max(user.max_health, user.health +
	num_recovery_units_poison);
}

// ����� ������������� �����
void Hero::show_characteristics()
{
	SetlocaleCP(1251);
	cout << "���������� �����: " << "x = " << x << ", y = " << y << ";" << endl;
	cout << "���������� �����: " << count_healing_poison << endl;
	cout << "���������� ������������� HP: " << num_recovery_units_poison << endl;
	cout << "������� ��������: " << endl;
	object.show_weared_artifacts(); // ������ ���������, ����� ������� ����������
	cout << "����������� �������: " << direction_gaze;
	cout << "��������: " << health << endl;
	cout << "����: " << damage << endl;
	cout << "������� ����� �����: " << armor << endl;
	cout << "������������ ��������: " << max_health << endl;
	cout << "������: " << gold << endl;
	cout << "���� ���������: " << hit_chance << endl;
	SetlocaleCP(866);
}

// ������� ������ 
void Hero::turn_right()
{
	void (Hero:: * tmp_ptr)() {};
	tmp_ptr = step_f;

	step_f = step_r;
	step_r = step_b;
	step_b = step_l;
	step_l = tmp_ptr;
}

// ������� ����� 
void Hero::turn_left()
{
	void (Hero:: * tmp_ptr)() {};
	tmp_ptr = step_f;

	step_f = step_l;
	step_l = step_b;
	step_b = step_r;
	step_r = tmp_ptr;
}

//��������������� ��������� ��� ������� ����� 
struct hero_and_mark
{
	Hero user;
	int mark;
};