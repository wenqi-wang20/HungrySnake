#include"Snake.hpp"
#include<conio.h>
#include"Tools.hpp"
#include<iostream>

void Snake::InitSnake()
{
    for (auto& point : snake){
        point.PrintCircular();
    }
}

void Snake::Move()
{
    switch (direction)
    {
    case Direction::UP:
        snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
        break;
    case Direction::DOWN:
        snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
    case Direction::LEFT:
        snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
    case Direction::RIGHT:
        snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));    
    default:
        break;
    }
    SetColor(14);
    snake.back().PrintCircular();
}

void Snake::NomalMove()
{
    Move();
    snake.front().Clear();
    snake.pop_front();
}

bool Snake::OverEgde()
{
    return snake.back().GetX() < 30 &&
           snake.back().GetY() < 30 &&
           snake.back().GetX() > 1 &&
           snake.back().GetY() > 1;
}

bool Snake::HitItself()
{
    std::deque<Point>::size_type cnt = 1;
    Point *head = new Point(snake.back().GetX(), snake.back().GetY());
    for (auto& point : snake){
        if (!(point == *head)){
            cnt++;
        }else{
            break;
        }
    }
    delete head;
    if (cnt == snake.size()){
        return true;
    }else{
        return false;
    }
}

bool Snake::ChangeDirection()
{
    char ch;
    if (kbhit()){
        ch = getch();
        switch (ch)
        {
        case -32:
            switch (ch)
            {
            case 72:
                if (direction != Direction::DOWN){
                    direction = Direction::UP;
                }
                break;
            case 80:
                if (direction != Direction::UP){
                    direction = Direction::DOWN;
                }
                break;      
            case 75:
                if (direction != Direction::RIGHT){
                    direction = Direction::LEFT;
                }
                break;
            case 77:
                if (direction != Direction::LEFT){
                    direction = Direction::RIGHT;
                }
                break;      
            default:
                break;
            }
            return true;
        case 27:   //ESC
            return false;
        default:
            return true;
        }
    }
    return true;
}

bool Snake::GetFood(const Food& cfood)
{
    if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y){
        return true;
    }else{
        return false;
    }
}

bool Snake::GetTimeFood(Food& cfood)
{
    if (snake.back().GetX() == cfood.time_x && snake.back().GetY() == cfood.time_y){
        cfood.time_flag = false;
        cfood.time_x = 0;
        cfood.time_y = 0;
        SetCursorPosition(1,0);
        std::cout << "                                         ";
        return true;
    }else{
        return false;
    }
}