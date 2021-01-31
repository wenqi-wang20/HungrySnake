#include"Controller.hpp"
#include<stdio.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")

int main(){
    //PlaySound(TEXT("C:\\Users\\19749\\Desktop\\DevProject\\.vscode\\vscode\\melancholy.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
    Controller c;
    c.Game();
    return 0;
}