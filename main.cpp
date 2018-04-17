#define _WIN32_WINNT 0x0500
#define W 40
#define H 24
#include <windows.h>
#include <iostream>
#include<conio.h>
#include <thread>
#include <cmath>
using namespace std;
#include "functions.h"
#include "menu.h"
#include "elements.h"
#include "game.h"

int main()
{
resizeScreen(200,100,600,600);
thread second(listenInput);

    while(1){
    int selection = showMenu();
    if(selection==1){
        startGame();
    }

    else if(selection==2){
        system("cls");
        gotoXY(5,4);
        cout<<"GOOD BYE!";
        Sleep(2000);
        system("cls");
        break;
    }

    }
   // second.detach();
    return 0;
}
