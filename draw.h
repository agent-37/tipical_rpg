#ifndef _DRAW_H_
#define _DRAW_H_
#include "game_map.h"
#include "hero.h"
#include "person.h"
//рисует просто картинку
void draw_picture(int y, int x, char* file_name);
//рисует миникарту
void draw_mini_map(Hero user, Game_map map, int y, int x);
//рисование боя
void draw_fight(Hero user, person monster, int mark);
//рисование закупки(сделать потом)
void draw_buy(int y, int x);
//рисование хождения по карте
void draw_walk(Hero user, Game_map map);

#endif // _DRAW_H_


