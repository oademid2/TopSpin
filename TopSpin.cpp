//


#include "TopSpin.h"
#include <ctime>

TopSpin::TopSpin(){
    sizeBoard = 20;
    spinSize = 4;
}

TopSpin::TopSpin(int size, int spinSize): TopSpinADT(){
    
    if(size<1)size = 20; //if the size of the board is let than one set it to default of 20
    
    if(spinSize>size)spinSize = 4; //if spin size is less than board size set default to 4
    
    for(int i=1;i<=size;i++) { //from 1 to the size of the board add a node in chronological order
        board.addData(i);
    }
    
    sizeBoard = size; //assign function parameter to class members
    this->spinSize = spinSize;
};



TopSpin::~TopSpin(){

}

ostream& operator<<(ostream& os, const TopSpin& ts)
{
    os<<" ";
    for(int i = 1;i<=ts.spinSize;i++)
    if(ts.board.getData(i)<9)os<<"---";
    else os<<"----";

    os<<"\n| "; //opening of spin window
    
    for(int i = 1;i<=ts.spinSize;i++){
        os << ts.board.getData(i)<<"  "; //display the numbers in the spin window
    }
    os<<"| "; //close spin window
    
    // display the other numbers
    for(int i = ts.spinSize+1;i<=ts.sizeBoard;i++){
        os << ts.board.getData(i)<<"  ";
    }
    os<<"\n ";
    
    for(int i = 1;i<=ts.spinSize;i++)
    if(ts.board.getData(i)<9)os<<"---";
    else os<<"----";
    
    return os;
}

void TopSpin::shiftLeft(){
    board.decrementHead(); // shift left by moving nodes  back by 1
};

void TopSpin::shiftRight(){
     board.incrementHead(); //shift right by moving nodes up by 1
}

void TopSpin::spin(){
    
    if(spinSize != 1){
    for (unsigned int k = 0; k < spinSize/2; k++)
    board.swap(1+k,spinSize-k); // swap the first and last numbers in window tray
                                //and swap the ones over after
    }
    
}



void TopSpin::random(unsigned int times){
   
    srand(time(NULL));
    
    for(int j=0;j<times;j++){ //for as many times as indicated
        
        int randNum;
        randNum = rand() % 20;
        
        for(int i=0;i<randNum;i++)shiftLeft(); //shift the game left a random number of times
        spin(); // and then spin after it's been shifted
    }
}

bool TopSpin::isSolved(){
    bool case1(1), case2(1), case3(1), case4(1);
    int key;
    
    for(int i=1;i<=sizeBoard;i++){
        if(board.getData(i) == 1){ //find the node which has 1
            key = i;
            break;
        }
    }
    
    
    //first I'm checking if it's in chronological order....
    for(int i=key;i<sizeBoard;i++){
        
        //I start by checking which if there are any cases out of order from 1 to the end
        if(!(board.getData(i) < board.getData(i+1))){
            case1 = 0; //if there is a single case case1 will automcatically be 0
            break;
        }
        else case1 = 1;//if there is no case it will remain as 1
    }
    
    if(key != 1){
    for(int i=1;i<key-1;i++){
        //check if all numbers from start to 1 is in order
        if(!(board.getData(i) < board.getData(i+1))){
            case2 = 0;//if there is a single case case2 will automcatically be 0
            break;
        }
        else case2 = 1;
    }
        
    }
    
    //Now I'm checking if it's in reverse order....
    for(int i=1;i<key;i++){
        
        //I start by checking which if there are any cases out of order from 1 to the end
        if(!(board.getData(i)  >board.getData(i+1))){
            case3 = 0; //if there is a single case case1 will automcatically be 0
            break;
        }
        else case3 = 1;//if there is no case it will remain as 1
    }
    
    if(key != 20){
        for(int i=key+1;i<sizeBoard;i++){
            //check if all numbers from start to 1 is in order
            if(!(board.getData(i) > board.getData(i+1))){
                case4 = 0;//if there is a single case case2 will automcatically be 0
                break;
            }
            else case4 = 1;
        }
        
    }

    if((case1 && case2)||(case3&&case4))return 1;//if the two cases for chronological or the two cases for revere are true then return 1
    else return 0; //other wise game is not solved
    
    
    
}





