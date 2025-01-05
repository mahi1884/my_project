#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int enemyX[3]={5,10,15};
int enemyY[3]={5,10,15};
int enemyDir[3]={1,-1,1};
void ShowMenu(){
cout<<"1. Start Game"<<endl;
cout<<"2. load Game"<<endl;
cout<<"3. Difficulty"<<endl;
cout<<"4. Help"<<endl;
cout<<"5. Exit"<<endl;
}
void drawMap(int playerX, int playerY){
for (int i=0 ;i<21 ;i++){
    for(int j=0;j<21;j++){
        if(i==0 || i==20 ||j==0 || j==20){
            cout<<"* ";}
            else if ((i==enemyX[0]&& j==enemyY[0])||
                     (i==enemyX[1] && j==enemyY[1]||
                      (i==enemyX[2] && j==enemyY[2]) )){
                        cout<<"E";}
            else if(i%2==0&&j%2==0){
            cout<<"XX";}
        else if (i == playerX && j == playerY){
            cout<<"S ";}
        else{cout<<"  ";}
    }
    cout<<endl;
}
}
void updateEnemies(){
for(int i=0; i<3 ; i++)
    if(enemyDir[i]==1&& enemyY[i]<19){
        enemyY[i]++;
    }
}
void movePlayer() {
    int playerX = 1, playerY = 1;
    char input;

    while (true) {
        system("cls");
        drawMap(playerX,playerY);
        input = _getch();
        if (input == 'w' && playerX > 1&& !(playerX-1==5&&playerY==5)) playerX--;
        else if (input == 's' && playerX < 18&& !(playerX+1==5&&playerY==5)) playerX++;
        else if (input == 'a' && playerY > 1&& !(playerX==5&&playerY-1==5)) playerY--;
        else if (input == 'd' && playerY < 18&&!(playerX==5&&playerY+1==5)) playerY++;
        else if (input == 'q') break;
    }
}
int main(){
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
