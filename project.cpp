#include<iostream>
using namespace std;
void ShowMenu(){
cout<<"1. Start Game"<<endl;
cout<<"2. load Game"<<endl;
cout<<"3. Difficulty"<<endl;
cout<<"4. Help"<<endl;
cout<<"5. Exit"<<endl;
}
int main(){
int choice;
while(true){
 systeam("cls");
 ShowMenu();
 cout<<"Enter your choice: ";
 cin<<choice;

}
return 0;
}
