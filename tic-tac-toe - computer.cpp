#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
using namespace std;

int x,y;
char ch, w[14]="invalid input", r[14]="             ", board[11]="#123456789";
void showBoard();
void curPos(short, short);
void playerInput();
void computerInput();
bool checkBoard(int);
char checkWin();
int toss();
void tictactoe();
int analyze();
int checkTwo();
int defenceTwo();
void boardValue();
//int trickTwo();

int main()
{
    int action;
    boardValue();
    while(1){
        curPos(10,0); printf("press 0: EXIT");
        curPos(10,1);printf("press 2: To TOSS and Start NEW GAME");
        curPos(18,3); scanf("%d",&action);
        system("cls");
        if(action==0) exit(1);
        else if(action==2)tictactoe();

    }
    curPos(0,14);
    return 0;
}

void tictactoe(){
    strcpy(board,"#123456789");
    showBoard();
    int who=toss();
    for(int i=1;i<=9;i++){
        i%2==who? playerInput():computerInput();
        if((ch = checkWin())!='0') {
            if(ch=='O') {curPos(10,16); printf("COMPUTER WINS!");}
            else {curPos(10,16); printf("YOU WIN!      ");}
            curPos(10,18);system("PAUSE");
            system("cls");
            break;
        }
        if(i==9) {
            curPos(10,16); printf("MATCH DRAW!");
            curPos(10,18);system("PAUSE");
            system("cls");
        }
    }
}
void boardValue(){
    printf("Instruction:  Board are indexed from 1 to 9 as shown bellow.");
    curPos(0,6);
    printf("   1   |   2   |   3   \n");
    printf("       |       |       \n");
    printf("=======|=======|=======\n");
    printf("   4   |   5   |   6   \n");
    printf("       |       |       \n");
    printf("=======|=======|=======\n");
    printf("   7   |   8   |   9   \n");
    printf("       |       |       \n\n\n");
    system("pause");
    system("cls");
}
void showBoard(){
    curPos(0,6);
    printf("       |       |       \n");
    printf("       |       |       \n");
    printf("=======|=======|=======\n");
    printf("       |       |       \n");
    printf("       |       |       \n");
    printf("=======|=======|=======\n");
    printf("       |       |       \n");
    printf("       |       |       \n\n\n");
}

int toss(){
    curPos(10,0);
    int who = rand()%2;
    if(who) printf("You win the toss.         ");
    else printf("Computer wins the toss. ");
    curPos(10,16);
    printf("                               ");
    return who;
}
bool checkBoard(int z){
    curPos(10,2);
    if(board[z]=='X'||board[z]=='O') {
        printf("%s",w);
        return false;
    }
    printf("%s",r);
    curPos(0,0);
    return true;
}
void playerInput(){
    curPos(10,2);
    printf("Your move                 ");
    curPos(22,2);
    while(scanf("%d",&x)){
        if(x<1||x>9) continue;
        if(checkBoard(x)){
            board[x]='X';
            break;
        }
    }
    if(x==1) {curPos(3,7); printf("X");}
    else if(x==2) {curPos(11,7); printf("X");}
    else if(x==3) {curPos(19,7); printf("X");}
    else if(x==4) {curPos(3,9); printf("X");}
    else if(x==5) {curPos(11,9); printf("X");}
    else if(x==6) {curPos(19,9); printf("X");}
    else if(x==7) {curPos(3,12); printf("X");}
    else if(x==8) {curPos(11,12); printf("X");}
    else if(x==9) {curPos(19,12); printf("X");}
}
void computerInput(){
    curPos(10,2);
    printf("Computer move              ");
    int y = analyze();
    board[y]='O';
    if(y==1) {curPos(3,7); printf("O");}
    else if(y==2) {curPos(11,7); printf("O");}
    else if(y==3) {curPos(19,7); printf("O");}
    else if(y==4) {curPos(3,9); printf("O");}
    else if(y==5) {curPos(11,9); printf("O");}
    else if(y==6) {curPos(19,9); printf("O");}
    else if(y==7) {curPos(3,12); printf("O");}
    else if(y==8) {curPos(11,12); printf("O");}
    else if(y==9) {curPos(19,12); printf("O");}
}
int analyze(){
    if(board[5]=='5') return 5;
    y = checkTwo();
    if(y) return y;
    y = defenceTwo();
    if(y) return y;
    //y = trickTwo();
    //if(y) return y;
    if((x==3||x==1)&&board[2]=='2') return 2;
    if((x==7||x==1)&&board[4]=='4') return 4;
    if((x==3||x==9)&&board[6]=='6') return 6;
    if((x==7||x==9)&&board[8]=='8') return 8;
    if((x==2||x==4)&&board[1]=='1') return 1;
    if((x==2||x==6)&&board[3]=='3') return 3;
    if((x==4||x==4)&&board[7]=='7') return 7;
    if((x==6||x==8)&&board[9]=='9') return 9;
    for(int k=1;k<=9;k++){
        if(board[k]!='X'&&board[k]!='O') return k;
    }

}
int checkTwo(){
    if(board[1]=='O'){
        if(board[1]==board[2]&&board[3]=='3') return 3;
        else if(board[1]==board[3]&&board[2]=='2') return 2;
        else if(board[1]==board[4]&&board[7]=='7') return 7;
        else if(board[1]==board[7]&&board[4]=='4') return 4;
    }

    if(board[9]=='O'){
        if(board[9]==board[3]&&board[6]=='6') return 6;
        else if(board[9]==board[6]&&board[3]=='3') return 3;
        else if(board[9]==board[7]&&board[8]=='8') return 8;
        else if(board[9]==board[8]&&board[7]=='7') return 7;
    }
    if(board[3]=='O'){
        if(board[3]==board[2]&&board[1]=='1') return 1;
        else if(board[3]==board[6]&&board[9]=='9') return 9;
    }
    if(board[7]=='O'){
        if(board[7]==board[4]&&board[1]=='1') return 1;
        else if(board[7]==board[8]&&board[9]=='9') return 9;
    }
    if(board[5]=='O'){
        if(board[5]==board[1]&&board[9]=='9') return 9;
        else if(board[5]==board[2]&&board[8]=='8') return 8;
        else if(board[5]==board[3]&&board[7]=='7') return 7;
        else if(board[5]==board[4]&&board[6]=='6') return 6;
        else if(board[5]==board[6]&&board[4]=='4') return 4;
        else if(board[5]==board[7]&&board[3]=='3') return 3;
        else if(board[5]==board[8]&&board[2]=='2') return 2;
        else if(board[5]==board[9]&&board[1]=='1') return 1;
    }
    return 0;
}
int defenceTwo(){
    if(board[1]=='X'){
        if(board[1]==board[2]&&board[3]=='3') return 3;
        if(board[1]==board[3]&&board[2]=='2') return 2;
        if(board[1]==board[4]&&board[7]=='7') return 7;
        if(board[1]==board[7]&&board[4]=='4') return 4;
    }

    if(board[9]=='X'){
        if(board[9]==board[3]&&board[6]=='6') return 6;
        if(board[9]==board[6]&&board[3]=='3') return 3;
        if(board[9]==board[7]&&board[8]=='8') return 8;
        if(board[9]==board[8]&&board[7]=='7') return 7;
    }
    if(board[3]=='X'){
        if(board[3]==board[2]&&board[1]=='1') return 1;
        if(board[3]==board[6]&&board[9]=='9') return 9;
    }
    if(board[7]=='X'){
        if(board[7]==board[4]&&board[1]=='1') return 1;
        if(board[7]==board[8]&&board[9]=='9') return 9;
    }
    if(board[5]=='X'){
        if(board[5]==board[1]&&board[9]=='9') return 9;
        if(board[5]==board[2]&&board[8]=='8') return 8;
        if(board[5]==board[3]&&board[7]=='7') return 7;
        if(board[5]==board[4]&&board[6]=='6') return 6;
        if(board[5]==board[6]&&board[4]=='4') return 4;
        if(board[5]==board[7]&&board[3]=='3') return 3;
        if(board[5]==board[8]&&board[2]=='2') return 2;
        if(board[5]==board[9]&&board[1]=='1') return 1;
    }
    return 0;
}
char checkWin(){
    if(board[1]==board[2]&&board[2]==board[3]) return board[1];
    else if(board[4]==board[5]&&board[5]==board[6]) return board[5];
    else if(board[7]==board[8]&&board[8]==board[9]) return board[7];
    else if(board[1]==board[4]&&board[4]==board[7]) return board[1];
    else if(board[2]==board[5]&&board[5]==board[8]) return board[5];
    else if(board[3]==board[6]&&board[6]==board[9]) return board[3];
    else if(board[1]==board[5]&&board[5]==board[9]) return board[5];
    else if(board[3]==board[5]&&board[5]==board[7]) return board[5];
    return '0';
}
void curPos(short px, short py)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { px, py };
    SetConsoleCursorPosition(hStdout, position);
}
