#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include"Controller.hpp"
#include"Tools.hpp"
#include"StartInterface.hpp"
#include"Map.hpp"
#include"Snake.hpp"
#include"Food.hpp"

void Controller::Start()
{
    SetWindowSize(41,32);
    SetColor(2);
    Startinterface *start = new Startinterface();
    start ->Action();
    delete start;

    SetCursorPosition(13,26);
    std::cout << "Press any key to start...";
    SetCursorPosition(13,27);
    system("pause");
}

void Controller::Select()
{
    SetColor(3);
    SetCursorPosition(13,26);
    std::cout << "                           ";
    SetCursorPosition(13,27);
    std::cout << "                           ";
    SetCursorPosition(6,21);
    std::cout << "请选择游戏难度： ";
    SetCursorPosition(6,22);
    std::cout << "（上下键选择，回车键确认）";
    SetCursorPosition(27,22);
    SetbackgroundColor();   //设置背景色显示选中的选项
    std::cout << "简单模式";
    SetCursorPosition(27,24);
    SetColor(3);
    std::cout << "普通模式";
    SetCursorPosition(27,26);
    std::cout << "困难模式";
    SetCursorPosition(27,28);
    std::cout << "炼狱模式";
    SetCursorPosition(0,31);
    score = 0;

    int ch;
    key = 1;
    bool flag = false;  //是否键入enter
    while((ch = _getch())){
        switch (ch)
        {
        case 72:     //向上选择up
            if (key > 1){  //此时选中项为第一项，无效
                switch (key)
                {
                case 2:
                    SetCursorPosition(27,22);
                    SetbackgroundColor();
                    std::cout << "简单模式";

                    SetCursorPosition(27,24);
                    SetColor(3);
                    std::cout << "普通模式";

                    key--;
                    break;
                case 3:
                    SetCursorPosition(27,24);
                    SetbackgroundColor();
                    std::cout << "普通模式";

                    SetCursorPosition(27,26);
                    SetColor(3);
                    std::cout << "困难模式";

                    key--;
                    break;
                case 4:
                    SetCursorPosition(27,26);
                    SetbackgroundColor();
                    std::cout << "困难模式";

                    SetCursorPosition(27,28);
                    SetColor(3);
                    std::cout << "炼狱模式";

                    key--;
                    break;                    
                }
            }
            break;
        case 80:    //向下选择down
            if (key < 4){  //此时选中项为第一项，无效
                switch (key)
                {
                case 1:
                    SetCursorPosition(27,24);
                    SetbackgroundColor();
                    std::cout << "普通模式";

                    SetCursorPosition(27,22);
                    SetColor(3);
                    std::cout << "简单模式";

                    key++;
                    break;
                case 2:
                    SetCursorPosition(27,26);
                    SetbackgroundColor();
                    std::cout << "困难模式";

                    SetCursorPosition(27,24);
                    SetColor(3);
                    std::cout << "普通模式";

                    key++;
                    break;
                case 3:
                    SetCursorPosition(27,28);
                    SetbackgroundColor();
                    std::cout << "炼狱模式";

                    SetCursorPosition(27,26);
                    SetColor(3);
                    std::cout << "困难模式";

                    key++;
                    break;                    
                }
            }
            break;            
        case 13:   //enter回车键
            flag = true;
            break;
        default:
            break;
        }
        if (flag){
            break;   //退出选择界面
        }
        SetCursorPosition(0,31);   //光标置于左下角
    }
    switch (key)
    {
    case 1:
        speed = 135;
        break;
    case 2:
        speed = 100;
        break;
    case 3:
        speed = 60;
        break;
    case 4:
        speed = 30;
        break;
    default:
        break;
    }
}

void Controller::DrawGame()
{
    system("cls");

    SetColor(3);   //绘制地图
    Map *init_map = new Map();
    init_map ->PrintInitmap();
    delete init_map;

    SetColor(3);
    SetCursorPosition(33,1);
    std::cout << "HungrySnake";
    SetCursorPosition(34,2);
    std::cout << "饿蛇";
    SetCursorPosition(31,4);
    std::cout << "难度： ";
    SetCursorPosition(36,5);
    switch (key)
    {
    case 1:
        std::cout << "简单模式";
        break;
    case 2:
        std::cout << "普通模式";
        break;
    case 3:
        std::cout << "困难模式";
        break;
    case 4:
        std::cout << "炼狱模式";
        break;
    default:
        break;
    }
    SetCursorPosition(31,7);
    std::cout << "得分: ";
    SetCursorPosition(37,8);
    std::cout << "     0";
    SetCursorPosition(33,13);
    std::cout << "方向键控制";
    SetCursorPosition(33,15);
    std::cout << "esc暂停";
}

int Controller::PlayGame()   //游戏循环
{
    //初始化蛇和食物
    Snake *csnake = new Snake();
    Food *cfood = new Food();
    SetColor(6);
    csnake ->InitSnake();
    srand((unsigned)time(NULL));  //随机数种子
    cfood ->DrawFood(*csnake);

    //游戏循环
    while(!csnake->OverEgde() && !csnake->HitItself()){ //判断蛇是否已经撞墙
        if (!csnake->ChangeDirection()){   //按esc时
            int tmp = Menu();  //调出菜单
            switch (tmp)
            {
            case 1:          //继续游戏
                break;
            case 2:          //重新开始
               delete csnake;
               delete cfood;
               return 1; 
            case 3:          //退出游戏
               delete csnake;
               delete cfood;
               return 2;
            default:
                break;
            }
        }

        if (csnake->GetFood(*cfood)){   //吃到食物
            csnake->Move();             //蛇增长
            UpdateScore(1);             //更新分数
            RewriteScore();             //重新绘制分数
            cfood->DrawFood(*csnake);   //重新绘制食物
        }else{
            csnake->NomalMove();
        }

        if (csnake->GetTimeFood(*cfood)){
            csnake->Move();
            UpdateScore(cfood->GetTimeBar()/5);   //根据进度条决定
            RewriteScore();
        }

        if (cfood->GetTimeFood()){    //如果此时有限时食物，则闪烁
            cfood->FlashTimeFood();
        }

        Sleep(speed);
    }

    delete csnake;   //蛇死亡，释放存储空间
    delete cfood;
    int tmp = GameOver();
    switch (tmp)
    {
    case 1:
        return 1;   //重新开始
    case 2:
        return 2;   //退出游戏
    default:
        return 2;   
    }
}

void Controller::UpdateScore(const int& tmp)
{
    score += key * 10 * tmp;  //游戏难度与传入的权重共同决定
}
void Controller::RewriteScore()
{
    //分数设置成6位右对齐
    SetCursorPosition(37,8);
    SetColor(11);
    int bit = 0;
    int tmp = score;
    while (tmp != 0){
        bit++;
        tmp /= 10;
    }    
    for (int i = 0; i < (6 - bit); i++){
        std::cout << " ";
    }
    std::cout << score;
}

int Controller::Menu()
{
    SetColor(11);
    SetCursorPosition(32,19);
    std::cout << "菜单：";
    Sleep(100);
    SetCursorPosition(34,21);
    SetbackgroundColor();
    std::cout << "继续游戏";
    Sleep(100);
    SetCursorPosition(34,23);
    SetColor(11);
    std::cout << "重新开始";
    Sleep(100);
    SetCursorPosition(34,25);
    std::cout << "退出游戏";
    SetCursorPosition(0,31);

    //菜单的选择部分
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while((ch = _getch())){
        switch (ch)
        {
        case 72:
            if (tmp_key > 1){
                switch (tmp_key)
                {
                case 2:
                    SetCursorPosition(34,21);
                    SetbackgroundColor();
                    std::cout << "继续游戏";
                    SetCursorPosition(34,23);
                    SetColor(11);
                    std::cout << "重新开始";

                    tmp_key--;
                    break;
                case 3:
                    SetCursorPosition(34,23);
                    SetbackgroundColor();
                    std::cout << "重新开始";
                    SetCursorPosition(34,25);
                    SetColor(11);
                    std::cout << "退出游戏";

                    tmp_key--;
                    break;                   
                }
            }
            break;
        case 80:
            if (tmp_key > 3){
                switch (tmp_key)
                {
                case 1:
                    SetCursorPosition(34,23);
                    SetbackgroundColor();
                    std::cout << "重新游戏";
                    SetCursorPosition(34,21);
                    SetColor(11);
                    std::cout << "继续游戏";

                    tmp_key++;
                    break;
                case 3:
                    SetCursorPosition(34,25);
                    SetbackgroundColor();
                    std::cout << "退出游戏";
                    SetCursorPosition(34,23);
                    SetColor(11);
                    std::cout << "重新开始";

                    tmp_key++;
                    break;                   
                }
            }
            break;
        case 13:
            flag = true;
            break;
        default:
            break;
        }
        if (flag){
            break;
        }
        SetCursorPosition(0,31);
    }
    if (tmp_key == 1){
        SetCursorPosition(32,19);
        std::cout << "      ";
        SetCursorPosition(34,21);
        std::cout << "        ";
        SetCursorPosition(34,23);
        std::cout << "        ";
        SetCursorPosition(34,25);
        std::cout << "        ";
    }
    return tmp_key;
}

void Controller::Game()
{
    Start();
    while(1){
        Select();
        DrawGame();
        int tmp = PlayGame();
        if (tmp == 1){
            system("cls");
            continue;
        }else if(tmp == 2){
            break;
        }else{
            break;
        }
    }
}

int Controller::GameOver()
{
    Sleep(500);
    SetColor(11);
    SetCursorPosition(10,8);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    SetCursorPosition(9,9);
    std::cout << "┃            Game Over!!!!              ┃";
    Sleep(30);
    SetCursorPosition(9,10);
    std::cout << "┃                                       ┃";
    Sleep(30);
    SetCursorPosition(9,11);
    std::cout << "┃           很遗憾，你挂了！             ┃";
    Sleep(30);
    SetCursorPosition(9,12);
    std::cout << "┃                                       ┃";
    Sleep(30);
    SetCursorPosition(9,13);
    std::cout << "┃         你的分数为：                 ┃";
    SetCursorPosition(24,13);
    std::cout << score;
    Sleep(30);
    SetCursorPosition(9,14);
    std::cout << "┃                                       ┃";
    Sleep(30);
    SetCursorPosition(9,15);
    std::cout << "┃         是否再来一局？？               ┃";
    Sleep(30);
    SetCursorPosition(9,16);
    std::cout << "┃                                       ┃";
    Sleep(30);
    SetCursorPosition(9,17);
    std::cout << "┃                                       ┃";
    Sleep(30);
    SetCursorPosition(9,18);
    std::cout << "┃  嗯嗯好        不了，我还是更爱学习   ┃";
    Sleep(30);
    SetCursorPosition(9,19);
    std::cout << "┃                                       ┃";
    Sleep(30);
    SetCursorPosition(9,20);
    std::cout << "┃                                       ┃";
    Sleep(30);
    SetCursorPosition(10,21);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

    Sleep(100);
    SetCursorPosition(11,18);
    SetbackgroundColor();
    std::cout << "嗯嗯好";
    SetCursorPosition(0,31);

    //选择菜单部分
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch())){
        switch (ch)
        {
        case 75:
            if (tmp_key > 1){
                SetCursorPosition(11,18);
                SetbackgroundColor();
                std::cout << "嗯嗯好";
                SetCursorPosition(18,18);
                SetColor(11);
                std::cout << "不了，我还是更爱学习";
                tmp_key--;
            }
            break;
        case 77:
            if (tmp_key < 2){
                SetCursorPosition(18,18);
                SetbackgroundColor();
                std::cout << "不了，我还是更爱学习";
                SetCursorPosition(11,18);
                SetColor(11);
                std::cout << "嗯嗯好";
                tmp_key++;
            }
            break;
        case 13:
            flag = true;
            break;
        default:
            break;
        }

        SetCursorPosition(0,31);
        if (flag){
            break;
        }
    }

    SetColor(11);
    switch (tmp_key)
    {
    case 1:
        return 1;   //重新开始
    case 2:
        return 2;   //退出游戏
    default:
        return 1;
    }
}