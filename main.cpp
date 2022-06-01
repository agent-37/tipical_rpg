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

using namespace std;
/* подключаем библиотеку GLUT */
#include "C:\Temp\glut-3.7.6-bin\glut.h"
/* начальная ширина и высота окна */
GLint Width = 1300, Height = 1000;
/* размер куба */
const int CubeSize = 200;
/* эта функция управляет всем выводом на экран */
void Display(void)
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    string s;

    Hero user;
    Game_map map;
    draw_walk(user, map);


    glFinish();
}

/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
    Width = w;
    Height = h;
    /* устанавливаем размеры области отображения */
    glViewport(0, 0, w, h);

    /* ортографическая проекция */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
/* Функция обрабатывает сообщения от клавиатуры */
void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'

    if (key == ESCAPE)
        exit(0);
}
/* Главный цикл приложения */
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Red square example");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);

    glutMainLoop();
}
