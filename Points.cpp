#include"Tools.hpp"
#include"Points.hpp"
#include<iostream>

void Point::Print()   //打印出方形边框
{
    SetCursorPosition(x,y);
    std::cout << "■";
}

void Point::PrintCircular() //打印小蛇
{
    SetCursorPosition(x,y);
    std::cout << "●";
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