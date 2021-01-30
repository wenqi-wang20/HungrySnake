#include"Food.hpp"
#include"Tools.hpp"
#include<cstdlib>
#include<iostream>

void Food::DrawFood(Snake& csnake)   //绘制食物，随机种子生成2-30以内的数字，如果与蛇身重叠则随机生成其他的地方，每五个种子出现一个限时食物
{
    while(1){
        int tmp_x = rand() % 30;
        int tmp_y = rand() % 30;
        if (tmp_x < 2)  {tmp_x += 2;}
        if (tmp_y < 2)  {tmp_y += 2;}
        bool flag = false;
        for (auto& point : csnake.snake){
            if (point.GetX() == tmp_x && point.GetY() == tmp_y || tmp_x == time_x && tmp_y == time_y){
                flag = true;
                break;
            }
        }
        if (flag){
            continue;
        }
        x = tmp_x;
        y = tmp_y;
        SetCursorPosition(x,y);
        SetColor(12);
        std::cout << "♥";
        cnt++;
        cnt %= 5;
        if (cnt == 0){
            DrawTimeFood(csnake);
        }
        break;
    }
}

void Food::DrawTimeFood(Snake& csnake)
{
    SetCursorPosition(5,0);
    SetColor(11);
    std::cout << "------------------------------------------";  //时间进度条
    time_bar = 42;
    while(1){
        int tmp_x = rand() % 30;
        int tmp_y = rand() % 30;
        if (tmp_x < 2)  {tmp_x += 2;}
        if (tmp_y < 2)  {tmp_y += 2;}
        bool flag = false;
        for (auto& point : csnake.snake){
            if (point.GetX() == tmp_x && point.GetY() == tmp_y || tmp_x == time_x && tmp_y == time_y){
                flag = true;
                break;
            }
        }
        if (flag){
            continue;
        }
        time_x = tmp_x;
        time_y = tmp_y;
        SetCursorPosition(time_x, time_y);
        SetColor(11);
        std::cout << "▉";
        time_flag = true;
        flash_flag = true;
        break;
    }
}

int Food::GetCnt()
{
    return cnt;
}

void Food::FlashTimeFood()
{
    SetCursorPosition(time_x, time_y);
    SetColor(11);
    if (flash_flag){
        std::cout << "  ";
        flash_flag = false;
    }else{
        std::cout << "▉";
        flash_flag = true;
    }

    SetCursorPosition(26,0);
    SetColor(12);
    for (int i = 42; i >= time_bar; i--){
        std::cout << "\b \b";  //  \b表示退格
    }
    time_bar--;
    if (time_bar == 0){
        SetCursorPosition(time_x, time_y);
        std::cout << "  ";
        time_flag = false;
        time_x = 0;
        time_y = 0;
    }
}

bool Food::GetTimeFood()
{
    return time_flag;
}

int Food::GetTimeBar()
{
    return time_bar;
}