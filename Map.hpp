#ifndef MAP_HPP
#define MAP_HPP

#include<vector>
#include"Points.hpp"
class Map         //定义地图类
{
public:
    Map(){        //默认构造函数
        for (int i = 1; i <= 30; i++){
            initmap.emplace_back(Point(i,1));
        }
        for (int j = 2; j <= 29; j++){
            initmap.emplace_back(Point(1,j));
            initmap.emplace_back(Point(30,j));
        }
        for (int i = 1; i <= 30; i++){
            initmap.emplace_back(Point(i,30));
        }
    }
    void PrintInitmap();
private:
    std::vector<Point> initmap; //此为初始地图
};
#endif