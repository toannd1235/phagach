
void gotoXY(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Colors the menu items/ or any other text output...
void colorText(int col){//12=red, 15=white---------------->this.colorit(12);  this.colorit(15);
        HANDLE hstdout;
        hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute( hstdout, col );
    }

void resizeScreen(int x,int y,int w,int h)
{
    HWND hand = GetConsoleWindow();
    SetConsoleTitle("Chat Program");
    SetWindowPos(hand,HWND_TOP,x,y,w, h, 0X2000);

}
