#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include "inventory.h"
#include "hero.h" 
//#include "person.h" 

using namespace std;

// ������
class Weapon
{
public:
	virtual void use_weapon() = 0;
};

// ���
class Knife :public Weapon
{
public:
	void use_weapon() override
	{
		// �������� ���������� ������(���������� ������)
	}
};

// ��������
class Gun :public Weapon
{
public:
	void use_weapon() override
	{

	}
};

// �������� - ������
class Machine_Gun :public Weapon
{
public:
	void use_weapon() override
	{

	}
};

// �������
class Club : public Weapon
{
public:
	void use_weapon() override
	{

	}
};