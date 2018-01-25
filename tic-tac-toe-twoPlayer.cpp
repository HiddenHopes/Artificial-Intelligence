#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
using namespace std;

char ch;
char w[14]="invalid input";
char r[14]="             ";
char board[11]="0123456789";
void showBoard();
void curPos(short, short);
void input(int);
bool checkBoard(int);
bool checkWin();
void tictactoe(){
    showBoard();
    for(int i=1;i<=9;i++){
        int x;
        curPos(0,0);
        scanf("%d",&x);
        if(checkBoard(x)){
            i%2==1? ch = 'O':ch='X';
            board[x]=ch;
            input(x);
            if(checkWin()) {
                if(ch=='X') {curPos(10,2); printf("x win");}
                else {curPos(10,2); printf("O win");}
                break;
            }
        }
        else i=i-1;
    }
}
int main()
{
    char c;
    while(1){
        c=getchar();
        tictactoe();
        if(c==27) exit(1);
    }
    curPos(0,14);
    return 0;
}

void showBoard(){
    curPos(0,6);
    printf("       |       |       \n");
    printf("   1   |   2   |   3   \n");
    printf("=======|=======|=======\n");
    printf("   4   |   5   |   6   \n");
    printf("       |       |       \n");
    printf("=======|=======|=======\n");
    printf("   7   |   8   |   9   \n");
    printf("       |       |       \n\n\n");
}
bool checkBoard(int x){
    curPos(10,2);
    if(board[x]=='X'||board[x]=='O') {
        printf("%s",w);
        return false;
    }
    printf("%s",r);
    return true;
}
void input(int x){
    if(x==1) {curPos(3,7); printf("%c",ch);}
    else if(x==2) {curPos(11,7); printf("%c",ch);}
    else if(x==3) {curPos(19,7); printf("%c",ch);}
    else if(x==4) {curPos(3,9); printf("%c",ch);}
    else if(x==5) {curPos(11,9); printf("%c",ch);}
    else if(x==6) {curPos(19,9); printf("%c",ch);}
    else if(x==7) {curPos(3,12); printf("%c",ch);}
    else if(x==8) {curPos(11,12); printf("%c",ch);}
    else if(x==9) {curPos(19,12); printf("%c",ch);}
}
bool checkWin(){
    if(board[1]==board[2]&&board[2]==board[3]) return true;
    else if(board[4]==board[5]&&board[5]==board[6]) return true;
    else if(board[7]==board[8]&&board[8]==board[9]) return true;
    else if(board[1]==board[4]&&board[4]==board[7]) return true;
    else if(board[2]==board[5]&&board[5]==board[8]) return true;
    else if(board[3]==board[6]&&board[6]==board[9]) return true;
    else if(board[1]==board[5]&&board[5]==board[9]) return true;
    else if(board[3]==board[5]&&board[5]==board[7]) return true;
    return false;
}
void curPos(short x, short y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };
    SetConsoleCursorPosition(hStdout, position);
}
