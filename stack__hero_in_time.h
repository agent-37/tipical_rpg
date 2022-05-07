#ifndef _STACK_HERO_IN_TIME_H_
#define _STACK_HERO_IN_TIME_H_
#include "Hero"

#define  max_size_stack 10
//���� ��� ��������, ���������� ����� ������
class stack_hero_in_time {
public:
	int size_stack;
	int ind;
	//����� ������� ������ �����, ��� ��� ��� ��������� ������������ � ������������ ������ 
	Hero ser_grey[max_size_stack];
	//������ ������� ����, ��� ��������� � ������(������, ������ ��� �������) 
	int in_cage[max_size_stack];
	stack() {
		ind = 0;
		size_stack = 0;
	~person() {}
protected:
	//��������� �� ������� ����� �� 1 ��� ����� � ������� �� ��������
	int previous_turn(Hero &_ser_grey, int &_in_cage) {
		if (size_stack == 0)
			return 0;
		_ser_grey = ser_grey[ind];
		_in_cage = in_cage[ind];
		ind = (ind + max_size_stack - 1) % max_size_stack;
		return 1;
	}
	//��������� ���������� ��������� (������ ��������� � ��� ������, ����� ����� ������� �� ����� ������)
	void add_turn(Hero _ser_grey) {
		if(size_stack < max_size_stack)
			size_stack++;
		ind  = (ind + 1) % max_size_stack;
		ser_grey[ind] = _ser_grey;
		in_cage[ind] = _in_cage;
	}	
}; 
 
#endif // _STACK_HERO_IN_TIME_H_
