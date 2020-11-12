#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#endif
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
using namespace std;


// player class
class Player{
    public:
    int health;
    string name;

    // constructor to add player name and initialize health to 15
    Player(string pname){
        name = pname;
        health = 15;
    }

    // attack function takes in another player object pointer to attack and random number for damage value
    void attack(Player *splayer, int rando){
        splayer->health -= rando; // decrasing attacked players health
        cout << splayer->name << " lost " << rando << " health!" << endl;
    }

    // defend function that takes random number and adds it to players health
    void defend(int rando){
        this->health += rando; // increasing health by random number
        cout << name << "'s health increased by " << rando << "!" << endl;
    }
}; // end of class




// main game loop
bool handler(Player *one, Player *two, int *turn){
    // displaying players' health
    cout << one->name << "'s health: " << one->health << endl;
    cout << two->name << "'s health: " << two->health << endl;

    int choice; // integer to hold users input and run correct function
    int rndnm = 0; // initializing int that will hold random num generated

    Player *current_p = ((*turn)%2) ? one : two; // intializing another object pointer to store current players turn object
    Player *ntcurrent_p = ((*turn)%2) ? two : one; // intializing another object pointer to store other players 
    // object in case of attack
    cout << current_p->name;
    cout << "'s turn!" << endl;
    cout << "Attack (1) or Defend (2)?" << endl;
    cin >> choice;


    // if statements to decide which fn to run according to player choice
    if(choice == 1){
        rndnm = rand() % 10; // generates random number between 0 and 9 each time function runs
        current_p->attack(ntcurrent_p, rndnm);
        (*turn)++;
        return 1;
    }else if(choice == 2){
        rndnm = rand() % 6; // generates random number between 0 and 5 each time function runs
        current_p->defend(rndnm);
        (*turn)++;
        return 1;
    }else if(choice == 3){
        return 0;
    }else{
        cout << "Please enter a valid choice" << endl;
        return 1;
    }
}