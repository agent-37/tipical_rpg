#ifndef _MONSTERS_H_
#define _MONSTERS_H_
#include "person.h"
#include "Hero.h"

class help : public person {
public:
	// ���������� ����� �����
	void heavy_blow(Hero& _hero);
};

// ����� ����
class ogre : public help {
public:
	ogre() { set_person(1000, 300, 200, 1000, 150, 50, "ogre.bmp"); }
	// ����������� ����
	void regeneration();
	virtual ~ogre() {}
};

// ����� �������
class skeleton : public person {
public:
	skeleton() { set_person(500, 200, 50, 500, 150, 30, "skeleton.bmp"); }
	// ��������� ������ �������� ������� � ������������ �������� �����
	void cursed_arrows(Hero& _hero);
	~skeleton() {}
};

// ����� ��������
class ghost : public person {
public:
	ghost() { set_person(500, 200, 50, 500, 150, 30, "ghost.bmp"); }
	// ����������� �������� ���������� ����
	bool invisibility();
	// ����� ������ �����
	void steal_gold(Hero& _hero);
	~ghost() {}
};

// ����� ������� (�����)
class dragon : public help {
public:
	dragon() { set_person(2000, 500, 500, 2000, 3000, 60, "dragon.bmp"); }
	// ��������� ����� �������
	void rage(Hero& _hero) { if (_hero.gold >= gold) damage += 200; }
	// ������ �������� - ����������� ��������� � ����
	void flight() { hit_chance = 30; }
	~dragon() {}
};

#endif // _MONSTERS_H_