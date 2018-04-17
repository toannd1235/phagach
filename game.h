int onPlay=1;
void listenInput(){
    int k[9] = { 13,32,36,37,38, 39, 40,41,42 };
    int i=0;
    while (1)
    {
        for (int n=0;n<9;n++)
        {
            i=k[n];
            if (GetAsyncKeyState(i)==-32767)
            {   //gotoxy(35,0);cout<<i;
                if (i==32)
                {
                    /*if(onpause==0){onpause=1;}
                    else if(onpause==1){onpause=0;}*/
                    onPlay=0;
                }
                if (i==37)
                {
                    //direction=left;
                    myPad.moveL();
                }
                else if (i==39)
                {
                    //direction=right;
                    myPad.moveR();
                }
                else if (i==38)
                {
                    //direction=up;
                }
                else if (i==40)
                {
                    //direction=down;
                }
            }
        }
    }
}
////////////////////

bricks myBrks;
ball myBall;
void startGame(){
    int lose=0;
    system("cls");
    gotoXY(45,6);
    cout<<"[SPACE] = Quit.";
    score=0;
    onPlay=1;
    resetboard();
    drawBorder();

    myPad.init();
    myBall = ball();
    myBall.draw();
    myBrks.init(7,4);

    while(onPlay){
    myBall.move();
    myBall.checkbounce();
    myBall.checkcollision();
    myBall.checkbound(onPlay,lose);


    for(int j=0;j<H;j++){
        for(int i=0;i<W;i++){
            gotoXY(i,j);
            if(board[i][j]==1){cout<<"8";}
            else if(board[i][j]==2){cout<<"0";}
            else if(board[i][j]==3){cout<<"0";}
            else if(board[i][j]==4){cout<<"0";}
            else {cout<<" ";}
        }
    }

    gotoXY(45,4);
    cout<<"SCORE:"<<score;
    }
    //

    if(lose==1){
        system("cls");
        drawBorder();
        gotoXY(10,6);cout<<"GAME OVER!";
        gotoXY(10,7);cout<<"SCORE:"<<score;
        Sleep(3000);
    }
}
