#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include "bmp.h"
#include "hero.h"
#include "monsters.h"
#include "person.h"
#include "draw.h"
#include "string_processing.h"
#include "stack.h"
using namespace std;

#include "C:\Temp\glut-3.7.6-bin\glut.h"


GLint Width = 1300, Height = 1000;

const int CubeSize = 200;

void Display(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    string s;

    Hero user;
    Game_map map;
    stack <Hero_and_map> stack_turn;
    map.mark_visited_cell(user.get_x(), user.get_y());
    draw_walk(user, map);
    draw_mini_map(user, map, 0, 804);
    glFinish();
    while (!user.check_died()) {
        string_processing(user, map, stack_turn);
        draw_walk(user, map);
        draw_mini_map(user, map, 0, 804);
        glFinish();
    }
}


void Reshape(GLint w, GLint h)
{
    Width = w;
    Height = h;

    glViewport(0, 0, w, h);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'

    if (key == ESCAPE)
        exit(0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Tipical rpg");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);


    glutMainLoop();
}

