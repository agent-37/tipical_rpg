#ifndef _TRADER_H_
#define _TRADER_H_
#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <fstream>
#include <Windows.h>
using namespace std;

class Trader
{
public:
	Trader();
	~Trader();

	// ������� ��������� �����
	bool trade_inventory(string inventory);

	// �������� ���������� ��������
	void show_inventory_trader();

private:
	// ��������� ���������� ��������
	multiset <string> trader_inventory;

	// �������� �� ��������� ���������� �������� (��� ���������� � �������� � ���� ����)
	multiset <string> ::iterator it_trader_inventory;

	// ������� ��������
	int revenue;

};


#endif // _TRADER_H_