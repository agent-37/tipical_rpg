#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include "inventory.h"
#include "person.h" 
#include "hero.h" 

using namespace std;

Hero::Hero()
{
	x = 0;
	y = 0;
	direction_gaze = 0;
	count_healing_poison = 0;
	num_recovery_units_poison = 0;
}

// ����������� ��������
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
	//SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");
	cout << "���������� �����: " << "x = " << x << ", y = " << y << ";" << endl;
	cout << "���������� �����: " << count_healing_poison << endl;
	cout << "���������� ������������� HP: " << num_recovery_units_poison << endl;
	cout << "������� ��������: " << endl;
	// object.show_weared_artifacts(); // ������ ���������, ����� ������� ����������
	cout << "����������� �������: " << direction_gaze << endl;
	cout << "��������: " << user.health << endl;
	cout << "����: " << user.damage << endl;
	cout << "������� ����� �����: " << user.armor << endl;
	cout << "������������ ��������: " << user.max_health << endl;
	cout << "������: " << user.gold << endl;
	cout << "���� ���������: " << user.hit_chance << endl;
	//SetConsoleCP(866);
}

// ������� ������ 
void Hero::turn_right()
{
	func_ptr tmp_ptr;
	tmp_ptr = step_f;

	step_f = step_r;
	step_r = step_b;
	step_b = step_l;
	step_l = tmp_ptr;
}

// ������� ����� 
void Hero::turn_left()
{
	func_ptr tmp_ptr;
	tmp_ptr = step_f;

	step_f = step_l;
	step_l = step_b;
	step_b = step_r;
	step_r = tmp_ptr;
}

// ��������������� ��������� ��� ������� ����� 
struct hero_and_mark
{
	Hero user;
	int mark;
};


int main()
{
	// ����
	Hero herot;
	cout << to_string(1) << " ��������� ������" << endl;
	herot.show_characteristics();

	herot.call_step_r();
	cout << to_string(2) << " ������ ��� ������" << endl;
	herot.show_characteristics();

	herot.turn_left();
	cout << to_string(3) << " ������� �����, �� ������ �� ������ ����������" << endl;
	herot.show_characteristics();

	herot.call_step_r();
	cout << to_string(4) << "��� ������ ������ �������� ������ ����������" << endl;
	herot.show_characteristics();

	system("pause");
	return 0;
}