#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
char map[21[21];
int enemyX[3]={5,11,15};
int enemyY[3]={5,11,15};
int enemyDir[3]={1,-1,1};
void ShowMenu(){
cout<<"1. Start Game"<<endl;
cout<<"2. load Game"<<endl;
cout<<"3. Difficulty"<<endl;
cout<<"4. Help"<<endl;
cout<<"5. Exit"<<endl;
}
void initializeMap(){
for(int i=0 ; i<21; i++){
    for(int j=0 ; j<21;i++){
        if(i==0 ||i==20||j==0||j==20){map[i][j]='*';}
        else if(i%2==0 && j%2==0){map[i][j]='X';}
        else if((i==1&&j==3)||(i==1 &&j==8)||(i==1&&j==15)||(i==2 && j==4)||(i==2&&j==9)){map[i][j]='_-';}
        else{map[i][j]='';}
    }}}
void drawMap(int playerX, int playerY){
for (int i=0 ;i<21 ;i++){
    for(int j=0;j<21;j++){
        if(i==playerX&&j==playerY){cout<<"s ";}
            else if ((i==enemyX[0]&& j==enemyY[0])||
                    (i==enemyX[1] && j==enemyY[1]||
                    (i==enemyX[2] && j==enemyY[2]) ))
                    {cout<<"E ";}
            else if(map[i][j]=='X'){cout<<"XX";}
        else if (map[i][j]=='_'){cout<<"_- ";}
        else if (map[i][j]=='*'){cout<<"* "}
        else{cout<<"  ";}
    }
    cout<<endl;
}
}
bool isWalkable(int x,int y){
return(map[x][y]==' ');}
void updateEnemies(){
for(int i=0; i<3 ; i++)
    if(enemyDir[i]==1&& enemyY[i]<19){enemyY[i]++;}
     else if (enemyDir[i] == -1 && enemyY[i] > 1) {enemyY[i]--;}
         else {enemyDir[i] *= -1;}
    }
    void updateEnemies(){
    for(int i=0 ;i<3 ;i++){
          if (enemyDir[i] == 1 && isWalkable(enemyX[i], enemyY[i] + 1)) {enemyY[i]++;}
        else if (enemyDir[i] == -1 && isWalkable(enemyX[i], enemyY[i] - 1)) {enemyY[i]--;}
             else {enemyDir[i] *= -1; }
    }}

void movePlayer() {
    int playerX = 1, playerY = 1;
    char input;

    while (true) {
        system("cls");
        drawMap(playerX,playerY);
        if (_kbhit()) {
        input = _getch();
        if (input == 'w' && isWalkable(playerX-1,playerY)) playerX--;
        else if (input == 's' && isWalkable(playerX+1,playerY)) playerX++;
        else if (input == 'a' && isWalkable(playerX,playerY-1)) playerY--;
        else if (input == 'd' && isWalkable(playerX,playerY+1)) playerY++;
        else if (input == 'q') break;
        }
        updateEnemies();
        Sleep(200);
}
}
int main(){
    initializeMap()
int choice;
while(true){
 system("cls");
 ShowMenu();
 cout<<"Enter your choice: ";
 cin>>choice;
 if(choice==1){
    movePlayer();
 }
 else if(choice==5){
    cout<<"Exiting.."<<endl;
    break;
 }
 else{
    cout<<"Invalid option!"<<endl;
 }
 system("pause");
}
return 0;
}
