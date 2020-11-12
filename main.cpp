/* A game where 2 players take turns to either attack opponent for a number between 0 and 9
 or defend themselves adding health of a number between 0 and 5

idea was taken from code the universe discord server
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"

using namespace std;

int main(){
    srand(time(NULL)); // initializing srand to get random numbereach time calling rand()
    string one, two; // strings to assign names for players
    int turn = 1; // int to hold current turn
    cout << "Welcome to text duel! Enter 3 in any choice to quit" << endl;
    cout << "Enter name for player 1" << endl;
    cin >> one;
    cout << "Enter name for player 2" << endl;
    cin >> two;
    Player *P_one = new Player(one); // initializing player one object
    Player *P_two = new Player(two); // initializing player two object
    while(handler(P_one, P_two, &turn) && (P_one->health>0) && (P_two->health>0)); // main game loop, if both healths are over 0 and
    // players havent chosen to end game, game will keep going


    // if statement to check whether someone won or users decided to end game early
    if(P_one->health <= 0){
        cout << P_two->name << " Wins!" << endl;
        cin >> turn; // to make sure user gets to see result
    }else if(P_two->health <= 0){
        cout << P_one->name << " Wins!" << endl;
        cin >> turn; // to make sure user gets to see result
    }


    // freeing memory used from heap
    delete P_one;
    delete P_two;
    P_one = 0;
    P_two = 0;
    return 0;
}


