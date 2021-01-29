#include"Map.hpp"
#include<Windows.h>

void Map::PrintInitmap()     //绘制地图，显示动画效果
{
    for (auto& point : initmap){   //利用auto自动判断类型，initmap为vector容器，point即为迭代器的值，也即每一个元素（一个Point类）
        point.Print();
        Sleep(10);
    }
    return ;
}