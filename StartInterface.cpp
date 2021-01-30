#include"StartInterface.hpp"
#include<windows.h>

void Startinterface::PrintFirst()   //开始时蛇进入
{
    for (auto& point : startsnake){
        point.Print();
        Sleep(speed);
    }
}

void Startinterface::PrintSecond()  //蛇从10移动到40
{
    for (int i = 10; i < 40; i++){
        /*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/
        int j = ( ((i-2)%8) < 4 )?( 15 + (i-2)%8 ) : ( 21 - (i-2)%8 );
        startsnake.emplace_back( Point(i, j) );
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();
        Sleep(speed);
    }
}

void Startinterface::PrintThird()  //蛇从接触右边到逐渐消失
{
    while(!startsnake.empty() || starttxt.back().GetX() < 33){
        if (!startsnake.empty()){
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();
        PrintText();
        Sleep(speed);
    }
}

void Startinterface::PrintText()
{
    for (auto& point : starttxt){
        if (point.GetX() >= 0){
            point.Print();
        }
    }
}

void Startinterface::ClearText()
{
    for (auto& point : starttxt){
        if (point.GetX() >= 0){
            point.Clear();
        }
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void Startinterface::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}