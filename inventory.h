#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <Windows.h>
#include "person.h" 
// �� ����� ���������� ���� #include "hero.h", ��� ��� ��������� ������

using namespace std;

// ���������
class Inventory
{
public:
	// ����������������� ��������
	void show_trader_artifacts();
	// �������� ������ ���������
	void show_weared_artifacts();
	// �������� ������ ���������
	void show_not_weared_artifacts();

	// ���������� �������� � ��������
	bool take_artifact_trader(string str);
	// ����� ��������
	bool take_off_artifact(string str);
	// ������ ��������
	bool put_on_artifact(string str);

	//�������� trader;

private:
	// ��������� ���������� ��������
	multiset <string> trader_inventory;
	// ��������� ������� ����������
	multiset <string> weared_inventory;
	// ��������� ������ ����������
	multiset <string> not_weared_inventory;

	// �������� �� ��������� ���������� �������� (��� ���������� � �������� � ���� ����)
	multiset <string> ::iterator it_trader_inventory;
	// �������� �� ��������� ������� ���������� (��� ���������� � �������� � ���� ����)
	multiset <string> ::iterator it_weared;
	// �������� �� ��������� ������ ���������� (��� ���������� � �������� � ���� ����)
	multiset <string> ::iterator it_not_weared;

};

#endif // _INVENTORY_H_