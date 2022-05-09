#include<iostream>
#include<string>
#include<cstdlib>
#include <ctime>
using namespace std;

void rules();

void rules(){
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";

}

int main(){
    char choice;
    int dice;
    string playerName;
    int guess;
    int balance;
    int bittingAmount;
    srand(time(0));  // Initialize random number generator.

    rules();

    cout<<"Enter a name"<<endl;
    getline(cin,playerName);

    cout<<"Enter balance"<<endl;
    cin>>balance;

    do{
        cout<<"Enter bitting amount : "<<endl;
        cin>>bittingAmount;

        do{
            if(bittingAmount<0 || bittingAmount>balance){
                cout<<"Bitting amount low than your balance."<<endl;
                 cout<<"Enter bitting amount : "<<endl;
                 cin>>bittingAmount;
            }
        }while(bittingAmount<0 || bittingAmount>balance);

        cout<<"Guess the number"<<endl;
        cin>>guess;

          do{
            if(guess<0 || guess>10){
                cout<<"Number should be between 1 to 10."<<endl;
                  cout<<"Guess the number"<<endl;
                  cin>>guess;
            }
        }while(guess<0 || guess>10);

        dice = rand()%10 +1;
        

        if(dice==guess){
             cout << "\n\nYou are in luck!! You have won Rs." << bittingAmount * 10<<endl;
             balance = balance+(bittingAmount*10);
        }else{
             cout << "Oops, better luck next time !! You lost $ "<< bittingAmount <<"\n"<<endl;
             balance = balance-bittingAmount;
        }
        
        cout<<"Continue Enter Y"<<endl;
        cin>>choice;

    }while(choice=='Y' || choice=='y');
    
return 0;
}

