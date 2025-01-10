#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
char map[21][21];
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
int brickBlocks[][2] = {
    {1, 2}, {1, 8}, {1, 19}, {1, 18}, {1, 17}, {2, 3}, {2, 7}, {2, 11},
    {3, 1}, {3, 5}, {3, 8}, {3, 18}, {4, 11}, {4, 19}, {5, 2}, {5, 3},
    {5, 6}, {5, 9}, {5, 11}, {5, 12}, {5, 13}, {5, 16}, {5, 18}, {6, 5},
    {6, 1}, {7, 1}, {7, 13}, {8, 1}, {8, 5}, {8, 13}, {8, 19}, {9, 1},
    {9, 9}, {9, 16}, {10, 1}, {10, 5}, {10, 7}, {10, 9}, {10, 19},
    {11, 6}, {11, 7}, {11, 12}, {11, 13}, {11, 15}, {11, 16}, {11, 19},
    {12, 3}, {12, 7}, {12, 13}, {12, 17}, {13, 9}, {13, 10}, {13, 14},
    {13, 15}, {13, 18}, {14, 1}, {14, 5}, {14, 11}, {15, 3}, {15, 7},
    {15, 11}, {15, 12}, {15, 13}, {15, 19}, {16, 3}, {16, 11}, {16, 17},
    {17, 5}, {17, 6}, {17, 14}, {17, 15}, {17, 18}, {18, 1}, {18, 13},
    {18, 17}, {18, 19}, {19, 1}, {19, 2}, {19, 6}, {19, 7}, {19, 12},
    {19, 13}, {19, 17}, {19, 18}
};
void initializeMap(){
for(int i=0 ; i<21; i++){
    for(int j=0 ; j<21;j++){
        if(i==0 ||i==20||j==0||j==20){map[i][j]='*';}
        else if(i%2==0 && j%2==0){map[i][j]='X';}
        else{map[i][j]=' ';}
    }}
    int numBricks = sizeof(brickBlocks) / sizeof(brickBlocks[0]);
    for (int k = 0; k < numBricks; k++) {
        int x = brickBlocks[k][0];
        int y = brickBlocks[k][1];
        map[x][y] = 'N';  // بلوک آجری
    }
}
void drawMap(int playerX, int playerY){
for (int i=0 ;i<21 ;i++){
    for(int j=0;j<21;j++){
        if(i==playerX&&j==playerY){cout<<"s ";}
            else if ((i==enemyX[0]&& j==enemyY[0])||
                    (i==enemyX[1] && j==enemyY[1]||
                    (i==enemyX[2] && j==enemyY[2]) ))
                    {cout<<"E ";}
            else if(map[i][j]=='X'){cout<<"XX";}
        else if (map[i][j]=='N'){cout<<"N ";}
        else if (map[i][j]=='*'){cout<<"* ";}
        else{cout<<"  ";}
    }
    cout<<endl;
}
}
bool isWalkable(int x,int y){
return(map[x][y]==' ');
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
        else if (input == 'e') {
             if (map[playerX - 1][playerY] == 'N') map[playerX - 1][playerY] = ' ';
        else if (map[playerX + 1][playerY] == 'N') map[playerX + 1][playerY] = ' ';
        else if (map[playerX][playerY - 1] == 'N') map[playerX][playerY - 1] = ' ';
        else if (map[playerX][playerY + 1] == 'N') map[playerX][playerY + 1] = ' ';
            }
            else if (input == 'k') { for (int i = 0; i < 3; i++) {
                    if ((enemyX[i] == playerX - 1 && enemyY[i] == playerY) ||
                        (enemyX[i] == playerX + 1 && enemyY[i] == playerY) ||
                        (enemyX[i] == playerX && enemyY[i] == playerY - 1) ||
                        (enemyX[i] == playerX && enemyY[i] == playerY + 1)) {
                        enemyX[i] = -1;
                        enemyY[i] = -1;
                        cout << "Enemy killed!" << endl;
                        break;
                    }
                }
            }
        else if (input == 'q') break;
        }
        updateEnemies();
        Sleep(200);
}
}
int main(){
initializeMap();
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
