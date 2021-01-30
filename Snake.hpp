#ifndef SNAKE_HPP
#define SNAKE_HPP

#include<deque>
#include"Points.hpp"
#include"Food.hpp"

class Food;
class Snake
{
public:
    enum Direction {UP, DOWN, LEFT, RIGHT};
    Snake(){
        snake.emplace_back(Point(14,8));
        snake.emplace_back(Point(15,8));
        snake.emplace_back(Point(16,8));
        direction = Direction::DOWN;
    }
    void InitSnake();
    void Move();
    void NomalMove();
    bool OverEgde();
    bool HitItself();
    bool ChangeDirection();
    bool GetFood(const Food& );
    bool GetTimeFood(Food& );
private:
    std::deque<Point> snake;
    Direction direction;
    friend class Food;  //将 Food 设置成友元，以便访问私有元素
};


#endif