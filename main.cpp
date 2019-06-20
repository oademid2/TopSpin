//

#include "TopSpin.h"
int main(){
    
    //CREATE A GAME....
    int numRandMoves, menuChoice;
    TopSpin game(20,10);
    
    //WELCOME USER AND COLLECT NUMBER FOR RANDOMIZATION....
    cout<<"Welcome To Top Spin!"<<endl;
    cout<<"Let's start! How many random moves would you like to initialize the game with?" ;
    cin>>numRandMoves;
    game.random(numRandMoves);
    cout<<"\n\nHere's your puzzle: "<<endl<<game<<endl;
    
    
    
    ///ALLOW USER TO MAKE A MOVE OR QUI
    while(1){
        cout << "\nChoose your next moves from the following options enter your choice by entering the corresponding number:" << endl<< "    1. Shift" << endl << "    2. Spin" << endl << "    3. Quit" << endl<<"ENTER OPTION: ";
        
        cin>>menuChoice;
        
        //MENU OUTCOMES
        
        //MAKE SSHIFT MOVE.....
        if(menuChoice == 1){
            int numOfShifts, dirOfShifts;
            
            //COLLECT NUMBER OF SHIFTS...
            cout<<"\nHow many shifts would you like? Enter number: ";
            cin>>numOfShifts;
            
            //COLLECT DIRECTION OF SHIFTS
            cout<<"\nWhich direction? Enter 1 for left and 2 for right: ";
            cin>>dirOfShifts;
            
            //MAKE SHIFTS BASED ON DIRECTION AND NUMBER
            if(dirOfShifts == 1)
                for(int i=0;i<numOfShifts;i++)game.shiftLeft();
            else if(dirOfShifts == 2)
                for(int i=0;i<numOfShifts;i++)game.shiftRight();
            
            //SHOW NEW PUZZLE....
            cout<<"\nA shift move has been made. This is the puzzle now: "<<endl<<game<<endl;
            
            //CHECK IF PUZZLE IS SOLVED...
            if(game.isSolved()){
                cout<<"Wow Congratulations! You solved the puzzle!"<<endl;
                break;
            }
        }
        //IF MAKE A SPIN....
        else if(menuChoice == 2){
            
            //SPIN THEN SHOW PUZZLE
            game.spin();
            cout<<"\n\nA spin has been made. This is the puzzle now: "<<endl<<game<<endl;
            
            //CHECK IF THE PUZZLE IS SOLVED
            if(game.isSolved()){
                cout<<"\n\nWOW Congratulations! You solved the puzzle!"<<endl;
                break;
            }
        }
        
        //IF THEY QUIT THAK THEM FOR PLAYING
        else if(menuChoice == 3){
            cout<<"\nThanks for playing!!"<<endl;
            break;
        }
       
        
    }
    
    
    return 0;
    
}
