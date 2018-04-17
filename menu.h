
//Display the menu

int showMenu(){
    system("cls");
    int index=1;
    char key=0;

  while(key!=13){
    gotoXY(4,3);//takes the console's cursor position to x=4,y=3
    colorText(15);
    if(index==1){colorText(12);}//makes the text white
        cout<<"START GAME";

    gotoXY(4,4);
    colorText(15);
    if(index==2){colorText(12);}
        cout<<"EXIT";
    colorText(15);

        key=getch();
        if(key==80){index++;}
        else if(key==72){index--;}
        if(index==5){index=1;}
        else if(index==0){index=4;}
    }
return index;
}
