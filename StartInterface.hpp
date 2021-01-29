#ifndef STARTINERFACE_HPP
#define STARTINERFACE_HPP

#include<vector>
#include<deque>
#include"Points.hpp"

class Startinterface
{
public:
    Startinterface() : speed(35){
        startsnake.emplace_back(Point(0,14));
        startsnake.emplace_back(Point(1,14));
        startsnake.emplace_back(Point(2,15));
        startsnake.emplace_back(Point(3,16));
        startsnake.emplace_back(Point(4,17));
        startsnake.emplace_back(Point(5,18));
        startsnake.emplace_back(Point(6,17));
        startsnake.emplace_back(Point(7,16));
        startsnake.emplace_back(Point(8,15));
        startsnake.emplace_back(Point(9,14));
        
        starttxt.emplace_back(Point(-26,14));//S
        starttxt.emplace_back(Point(-25,14));
        starttxt.emplace_back(Point(-27,15));
        starttxt.emplace_back(Point(-26,16));
        starttxt.emplace_back(Point(-25,17));
        starttxt.emplace_back(Point(-27,18));
        starttxt.emplace_back(Point(-26,18));

        starttxt.emplace_back(Point(-23, 14));//N
        starttxt.emplace_back(Point(-23, 15));
        starttxt.emplace_back(Point(-23, 16));
        starttxt.emplace_back(Point(-23, 17));
        starttxt.emplace_back(Point(-23, 18));
        starttxt.emplace_back(Point(-22, 15));
        starttxt.emplace_back(Point(-21, 16));
        starttxt.emplace_back(Point(-20, 17));
        starttxt.emplace_back(Point(-19, 14));
        starttxt.emplace_back(Point(-19, 15));
        starttxt.emplace_back(Point(-19, 16));
        starttxt.emplace_back(Point(-19, 17));
        starttxt.emplace_back(Point(-19, 18));

        starttxt.emplace_back(Point(-17, 18));//A
        starttxt.emplace_back(Point(-16, 17));
        starttxt.emplace_back(Point(-15, 16));
        starttxt.emplace_back(Point(-14, 15));
        starttxt.emplace_back(Point(-14, 16));
        starttxt.emplace_back(Point(-13, 14));
        starttxt.emplace_back(Point(-13, 16));
        starttxt.emplace_back(Point(-12, 15));
        starttxt.emplace_back(Point(-12, 16));
        starttxt.emplace_back(Point(-11, 16));
        starttxt.emplace_back(Point(-10, 17));
        starttxt.emplace_back(Point(-9, 18));

        starttxt.emplace_back(Point(-7, 14));//K
        starttxt.emplace_back(Point(-7, 15));
        starttxt.emplace_back(Point(-7, 16));
        starttxt.emplace_back(Point(-7, 17));
        starttxt.emplace_back(Point(-7, 18));
        starttxt.emplace_back(Point(-6, 16));
        starttxt.emplace_back(Point(-5, 15));
        starttxt.emplace_back(Point(-5, 17));
        starttxt.emplace_back(Point(-4, 14));
        starttxt.emplace_back(Point(-4, 18));

        starttxt.emplace_back(Point(-2, 14));//E
        starttxt.emplace_back(Point(-2, 15));
        starttxt.emplace_back(Point(-2, 16));
        starttxt.emplace_back(Point(-2, 17));
        starttxt.emplace_back(Point(-2, 18));
        starttxt.emplace_back(Point(-1, 14));
        starttxt.emplace_back(Point(-1, 16));
        starttxt.emplace_back(Point(-1, 18));
        starttxt.emplace_back(Point(0, 14));
        starttxt.emplace_back(Point(0, 16));
        starttxt.emplace_back(Point(0, 18));
    }
    void PrintFirst();
    void PrintSecond();
    void PrintThird();
    void PrintText();
    void ClearText();
    void Action();
private:
    int speed;    //开场动画移动的速度
    std::deque<Point> startsnake;    //开场蛇点列
    std::vector<Point> starttxt;  //开场文字
};

#endif