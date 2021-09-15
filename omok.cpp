#include <iostream>
#include <string.h>
using namespace std;

#define MAXROW 15
#define MAXCOL 15
#define MAXNAME 10

class Omok{
private:
    int arr_OmokPan[MAXROW][MAXCOL];
    int in_x, in_y;
    char *player1, *player2;
public:
    Omok();                           //Initialize the variable
    bool FindWinner(int k);           //Check the winner
    void InputPoint();                //Enter the coordinate of the grid
    void PrintPoint();                //view the stone
    void InputID();                   //input id
    void BattleGame();                //game
    void ViewGuide();                 //view guide of the game
};

void Omok::ViewGuide(){
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << '\n';
    cout << "┃         ****Omok Game****           ┃" << '\n';
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << '\n';
    cout << "┃                                     ┃" << '\n';
    cout << "┃ 1. Put each ID of player 1 and 2    ┃" << '\n';
    cout << "┃ 2. Enter the coordinate of the grid ┃" << '\n';
    cout << "┃    until the winner being decided   ┃" << '\n';
    cout << "┃ 3. Show the winner                  ┃" << '\n';
    cout << "┃ 4. Terminate the program            ┃" << '\n';
    cout << "┃                                     ┃" << '\n';
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << '\n';
}


Omok::Omok(){
    in_x=0;
    in_y=0;
    
    //initialize the grid
    for(int i=0;i<MAXROW;i++)
        for(int j=0;j<MAXCOL;j++)
            arr_OmokPan[i][j]=0;
        
}


void Omok::InputID() {
    char p_name[MAXNAME];
    cout << "Input player1 ID : ";
    while(1){
        cin >> p_name;
        if(strlen(p_name)>MAXNAME)
            continue;
        else
            break;
    }
    player1 = new char[strlen(p_name)];
    strcpy(player1, p_name);
    
    char p_name2[MAXNAME];
    cout << "Input player2 ID : ";
    while(1){
        cin >> p_name2;
        if(strlen(p_name2)>MAXNAME)
            continue;
        else
            break;
    }
    player2 = new char[strlen(p_name2)];
    strcpy(player2, p_name2);
    cout << "Start Omok Game(" << player1 << " VS " << player2 << ")!!!"<< '\n';
}

void Omok::PrintPoint(void){
    int i,j;
    for(i=0; i<MAXROW; i++){
        for(j=0; j<MAXCOL; j++){
            if(arr_OmokPan[i][j] == 0)
                cout<< "┼";
            else if(arr_OmokPan[i][j] == 1)
                cout<< "●";
            else if(arr_OmokPan[i][j] == 2)
                cout<< "○";
        }
        cout<< i+1 << '\n';
    }
    for(j=0;j<MAXCOL;j++){
        cout.width(1);
        cout<< j+1;
    }
    cout << endl;
}

void Omok::InputPoint(void){
    //x coordinate value
    cout << "Enter the value of x coordinate(1~" << MAXCOL << "):"<<'\n';
    cin >> in_y;
    while (in_y < 1 || in_y > MAXCOL){
        cout << "It is not a valid value.";
        cout << "Enter the value of x coordinate(1~" << MAXCOL << "):"<< '\n';
        cin >> in_y;
    }
    // y coordinate value
    cout << "Enter the value of y coordinate(1~" << MAXROW << ")"<< '\n';
    cin >> in_x;
    while (in_x < 1 || in_x > MAXROW){
        cout << "It is not a valid value.";
        cout << "Enter the value of y coordinate(1~" << MAXROW << ")"<< '\n';
        cin >> in_x;
    }
}

bool Omok::FindWinner(int k){
    int i,j;
    
    for(i=0;i<MAXROW;i++){
        for(j=0;j<MAXCOL;j++){
            if(arr_OmokPan[i][j]==k && arr_OmokPan[i+1][j+1]==k && arr_OmokPan[i+2][j+2]==k && arr_OmokPan[i+3][j+3]==k && arr_OmokPan[i+4][j+4]==k)
                return true;
            else if(arr_OmokPan[i][j]==k && arr_OmokPan[i-1][j+1]==k && arr_OmokPan[i-2][j+2]==k && arr_OmokPan[i-3][j+3]==k && arr_OmokPan[i-4][j+4]==k)
                return true;
            else if(arr_OmokPan[i][j]==k && arr_OmokPan[i-1][j+1]==k && arr_OmokPan[i-2][j+2]==k && arr_OmokPan[i-3][j+3]==k && arr_OmokPan[i-4][j+4]==k)
                return true;
            else if(arr_OmokPan[i][j]==k && arr_OmokPan[i][j+1]==k && arr_OmokPan[i][j+2]==k && arr_OmokPan[i][j+3]==k && arr_OmokPan[i][j+4]==k)
                return true;
            else if(arr_OmokPan[i][j]==k && arr_OmokPan[i+1][j]==k && arr_OmokPan[i+2][j]==k && arr_OmokPan[i+3][j]==k && arr_OmokPan[i+4][j]==k)
                return true;
        }
    }
    return false;
}

void Omok::BattleGame(){
    ViewGuide();
    InputID();
    PrintPoint();
    int player=0;
    
    while(1) {
        //select the player
        if (player%2 == 0)
            cout << "★" << player1 << "★";
        else
            cout << "★" << player2 << "★";
        
        InputPoint();
        cout << endl;
        
        if (arr_OmokPan[in_x-1][in_y-1] == 0) {
            arr_OmokPan[in_x-1][in_y-1] = player%2 + 1;
            PrintPoint();
            if (FindWinner(player%2+1)) {
                if (player%2+1 == 1)
                    cout << player1;
                else
                    cout << player2;
                cout << "is winner!" << endl;
                break;
            }
            player++;
        }
        else{
            cout << "It is not a valid coordinate. Please enter again." << '\n';
            break;
        }
    }
}

int main(){
    Omok o;
    o.BattleGame();
    
    return 0;
}
