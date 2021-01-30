#include"Tools.hpp"
#include<Windows.h>
#include<cstdio>

void SetWindowSize(int cols, int lines)//设置窗口的长和宽
{
    system("title HungrySnake");  //设置控制台的标题
    char wincmd[35];
    sprintf_s(wincmd,35, "mode con cols=d% lines=%d", cols*2, lines);//方便将其他类型的数据转化为字符串的形式进行储存
    system(wincmd);//cols=88, lines=88设置窗口宽度、高度
}

void SetCursorPosition(const int x, const int y)//设置光标的位置
{
    COORD Position;
    Position.X = x*2;
    Position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}

void SetColor(int colorID)//设置文本颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetbackgroundColor()//设置文本的背景颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}