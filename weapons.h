#include <iostream> 
#include <algorithm> 
#include <set> 
#include <string> 
#include <iterator> 
#include "inventory.h"
#include "hero.h" 
//#include "person.h" 

using namespace std;

// оружие
class Weapon
{
public:
	virtual void use_weapon() = 0;
};

// нож
class Knife :public Weapon
{
public:
	void use_weapon() override
	{
		// уточнить реализацию ударов(применения оружия)
	}
};

// пистолет
class Gun :public Weapon
{
public:
	void use_weapon() override
	{

	}
};

// пистолет - пулемёт
class Machine_Gun :public Weapon
{
public:
	void use_weapon() override
	{

	}
};

// дубинка
class Club : public Weapon
{
public:
	void use_weapon() override
	{

	}
};