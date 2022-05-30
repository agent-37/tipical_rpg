#ifndef _DRAW_H_
#define _DRAW_H_
#include "game_map.h"
#include "hero.h"
#include "person.h"
//������ ������ ��������
void draw_picture(int y,int x,char* file_name);
//������ ���������
void draw_mini_map(game_map map, int y, int x);
//��������� ���
void draw_fight(Hero user, person monster);
//��������� �������(������� �����)
void draw_buy(int y, int x);
//��������� �������� �� �����
void draw_walk(game_map map,Hero user,int y, int x);

#endif // _DRAW_H_

