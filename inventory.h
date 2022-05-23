#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include "weapons.h" 
#include "hero.h" 
//#include "person.h" 

using namespace std;

// ���������
class Inventory
{
public:

	// ����� ������ ����������
	void show_weared_artifacts();
	// ����� ������ ����������
	void show_not_weared_artifacts();
	// ����� ���������
	void take_off_artifact();
	// ������ ���������
	void put_on_artifact();


private:

	// ������
	multiset <string> weapons;
	// ������� ���������
	multiset <string> weared_inventory;
	// ������ ���������
	multiset <string> not_weared_inventory;

	// ������ : ��������
	multiset <string> ::iterator it_weapons;
	// ������� ��������� : ��������
	multiset <string> ::iterator it_weared;
	// ������ ��������� : ��������
	multiset <string> ::iterator it_not_weared;

};

// ����� ������ ����������
inline void Inventory::show_weared_artifacts()
{
	for (multiset <string> ::iterator it_weared = weared_inventory.begin(); it_weared != weared_inventory.end(); ++it_weared)
		cout << *it_weared << endl;
}

// ����� ������ ����������
inline void Inventory::show_not_weared_artifacts()
{
	for (multiset <string> ::iterator it_not_weared = weared_inventory.begin(); it_not_weared != weared_inventory.end(); ++it_not_weared)
		cout << *it_not_weared << endl;
}

// ����� ���������
inline void Inventory::take_off_artifact()
{
	if (weared_inventory.size() > 0)
	{
		not_weared_inventory.insert(*(weared_inventory.rbegin()));
		weared_inventory.erase(--weared_inventory.end());
	}
	else
		cout << "��� ��������� �����" << endl;
}

// ������ ���������
inline void Inventory::put_on_artifact()
{
	if (not_weared_inventory.size() > 0)
	{
		weared_inventory.insert(*(not_weared_inventory.rbegin()));
		not_weared_inventory.erase(--not_weared_inventory.end());
	}
	else
		cout << "��� ��������� ������" << endl;
}