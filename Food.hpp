#ifndef FOOD_HPP
#define FOOD_HPP

#include"Snake.hpp"
class Snake;
class Food
{
public:
    Food() : cnt(0),flash_flag(false),time_flag(false),x(0),y(0),time_x(0),time_y(0),time_bar(0) {}
    void DrawFood(Snake& );
    void DrawTimeFood(Snake& );
    int GetCnt();
    void FlashTimeFood();
    bool GetTimeFood();
    int GetTimeBar();
private:
    int cnt;   //食物数量
    bool flash_flag;  //食物闪烁标志
    bool time_flag;    //限时食物标志
    int x, y;   //食物出现的坐标
    int time_x, time_y;  //限时食物出现的坐标
    int time_bar;   //限时食物时间进度条
    friend class Snake;
};

#endif