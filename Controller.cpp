#include<iostream>
namespace SNAKE{
    std::string name = "I am ready!";
    std::string begin = "Begin right now!";
}

int main(){
    using namespace SNAKE;
    std::cout << name;
    std::cout << std::endl << begin;
    system("pause");
    return 0;
}