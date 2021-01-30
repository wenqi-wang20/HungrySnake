#include"Controller.hpp"
#include<Windows.h>
//#pragma comment(lib,"Winmm.lib")

int main(){
    //PlaySound(TEXT("C:\\Users\\19749\\Desktop\\DevProject\\.vscode\\vscode\\melancholy.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
    Controller c;
    c.Game();
    return 0;
}