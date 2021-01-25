#include"Tools.hpp"
#include"Points.hpp"
#include<iostream>

void Point::Print()   //打印出小狗
{
    SetCursorPosition(x,y);
    std::cout << "🐕";
}

void Point::PrintCircular() //打印小鱼
{
    SetCursorPosition(x,y);
    std::cout << "🐟";
}

void Point::Clear() //清除输出
{
    SetCursorPosition(x,y);
    std::cout << "  ";
}

void Point::ChangePosition(const int x, const int y)
{
    this->x = x;
    this->y = y;
}