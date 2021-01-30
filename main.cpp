#include"Controller.hpp"
#include<Windows.h>
#pragma comment(lib,"Winmm.lib")

int main() {
    PlaySound(TEXT("./melancholy.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    Controller c;
    c.Game();
    return 0;
}