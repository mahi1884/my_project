#include<iostream>
using namespace std;
void ShowMenu(){
cout<<"1. Start Game"<<endl;
cout<<"2. load Game"<<endl;
cout<<"3. Difficulty"<<endl;
cout<<"4. Help"<<endl;
cout<<"5. Exit"<<endl;
}
void drawMap(){
for (int i=0 ;i<20 ;i++){
    for(int j=0;j<20;j++){
        if(i==0 || i==19 ||j==0 || j==19){
            cout<<"X";}
        else if (i==1 && j==1){
            cout<<"S";}
        else{cout<<" ";}
    }
    cout<<endl;
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
    system("cls");
    drawMap();
    system("pause");
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
