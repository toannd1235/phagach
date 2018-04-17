int score;
int board[100][100];

void resetboard(){
    for(int j=0;j<H;j++){
        for(int i=0;i<W;i++){
            board[i][j]=0;
        }
    }
}
void drawPoint(int x, int y, int value){
     board[x][y]=value;
     }
void erasePoint(int x, int y){
     board[x][y]=0;
}
void drawBorder(){
    for(int i=0;i<W;i++) {drawPoint(i,0,1); }
    for(int i=0;i<W;i++) {drawPoint(i,H-1,1); }
    for(int j=0;j<H;j++) {drawPoint(0,j,1); }
    for(int j=0;j<H;j++) {drawPoint(W-1,j,1); }
}
//////BALL CLASS////////////////////////////////////
class ball {
public:
int x, y;
int speedX,speedY;
ball(){
x=15;
y=17;
speedX=1;
speedY=-1;
}
void draw(){
    drawPoint(x,y,3);
    }
void move(){
    if(board[x][y]==3){
    erasePoint(this->x,this->y);
    }
    this->x=this->x+speedX;
    this->y=this->y+speedY;
    if(board[x][y]==0){
    drawPoint(x,y,3);
    }
}
void checkbounce(){
     if(x>=W-1){speedX=-1*speedX;}
     if(x<=0){speedX=-1*speedX;}
     if(y<=0){speedY=-1*speedY;}
     if(y>=H-1){speedY=-1*speedY;}

     if(board[x][y]==4){speedY=-1*speedY;}
}
void checkcollision(){
    if(board[this->x][this->y]==2){
        erasePoint(this->x,this->y);
        ////////////////////////////
     if(board[x-1][y]==0){speedX=-1;}
     if(board[x+1][y]==0){speedX=1;}
     if(board[x][y+1]==0){speedY=1;}
     if(board[x][y-1]==0){speedY=-1;}
        ////////////////////////////
     if(board[x-1][y+1]==0){speedY=-1*speedY;speedX=-1*speedX;}
     if(board[x+1][y+1]==0){speedY=-1*speedY;speedX=-1*speedX;}
     if(board[x+1][y-1]==0){speedY=-1*speedY;speedX=-1*speedX;}
     if(board[x-1][y-1]==0){speedY=-1*speedY;speedX=-1*speedX;}

     score+=10;
    }

    }
void checkbound(int &onplay,int &lose){
    if(this->y >= H-1){
        onplay=0;
        lose=1;
    }
}

};
//////////////////////////////////////////
//////BRICKS CLASS////////////////////////////////////
class bricks {
public:
void init(int startX, int startY){
    for(int j=0;j<H;j++){
        for(int i=0;i<W;i++){
        if(i>=startX & i<W-startX & j>=startY &j<startY+4){board[i][j]=2;}
        }
    }
    }
void vanish(int x, int y){
    board[x][y]=0;
}
};
//////////////////////////////////////////
//////BRICK CLASS////////////////////////////////////
class brick {
public:
int x, y, stat;
void draw(){
    drawPoint(x,y,2);
    }
};
//////////////////////////////////////////
//////BRICK CLASS////////////////////////////////////
class pad {
public:
int x;  //Position of the pad
int length;
void init(){
    this->x=10;
    this->length=18;
    for(int i=this->x;i<this->x+this->length;i++){drawPoint(i,H-2,4);}
    }
void moveL(){
    //Sleep(100);
    x--;
    if(x<1){x=1;}
    for(int i=1;i<x;i++){drawPoint(i,H-2,0);}
    for(int i=x;i<x+length;i++){drawPoint(i,H-2,4);}
    for(int i=x+length;i<W-1;i++){drawPoint(i,H-2,0);}
}
void moveR(){
    x++;
    if(x>W-length-1){x=W-length-1;}
    for(int i=1;i<x;i++){drawPoint(i,H-2,0);}
    for(int i=x;i<x+length;i++){drawPoint(i,H-2,4);}
    for(int i=x+length;i<W-1;i++){drawPoint(i,H-2,0);}
}
}myPad;
//////////////////////////////////////////


