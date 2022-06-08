#ifndef _TRADER_H_
#define _TRADER_H_
#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include <fstream>
#include <Windows.h>
#define name_file "artifacts.txt"
using namespace std;

class Trader
{
public:
	Trader();
	~Trader();

	// ������� ��������� �����
	bool trade_inventory(string inventory);

	// ����� ��������� �� ������
	bool take_inventory_from_warehouse(string str);

	// �������� ��������� �� �����	
	bool put_inventory_on_warehouse(string str);

	// �������� ���������� ��������
	void show_inventory_trader();

protected:
	// ��������� ���������� ��������
	multiset <pair<string, int>> trader_inventory;

	// ��������� ���������� ������
	multiset <string> warehouse_inventory;

	// �������� �� ��������� ���������� �������� (��� ���������� � �������� � ���� ����)
	multiset <pair<string, int>> ::iterator it_trader_inventory;

	// �������� �� ��������� ���������� ������
	multiset <string> it_warehouse_inventory;

	// ������� ��������
	int revenue;
};

#endif // _TRADER_H_