//

#include "TopSpinADT.h"
#include <string>
#include "CDLL.h"
using namespace std;

class TopSpin:public TopSpinADT{
    
public:
    TopSpin();
    TopSpin(int size, int spinSize);
    ~TopSpin();
    int sizeBoard;
    int spinSize;
    CDLL<int> board;
    
    void shiftLeft();
    void shiftRight();
    void spin();
    void random(unsigned int times);
    bool isSolved();
    
    
    friend std::ostream& operator<< (std::ostream& os, const TopSpin& ts);
    
};
