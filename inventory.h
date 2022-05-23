#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
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
