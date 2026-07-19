#ifndef RUBIKS_CUBE_SOLVER_CORNERDBMAKER_H
#define RUBIKS_CUBE_SOLVER_CORNERDBMAKER_H
#include "CornerPatternDatabase.h"
#include "../Model/RubiksCube3dArray.cpp"
/*
Now that you have a perfect mathematical layout to represent any corner state as a unique 1D index, CornerDBMaker runs a 
Breadth-First Search (BFS) algorithm starting from a perfectly solved cube, it simulates every possible move layer-by-layer 
up to a depth of 8 moves to pre-calculate the minimum steps required to solve the corners. This will form our heuristics in IDA* 
algorithm. 

This class creates the cornerPattern database and dumps that data straight to a file using the low-level binary copy 
methods toFile() and fromFile() we discussed in "PatternDatabase.cpp" .

*/
using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};


#endif //RUBIKS_CUBE_SOLVER_CORNERDBMAKER_H