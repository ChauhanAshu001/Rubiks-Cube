/*
The Core Concept of IDDFS (Iterative deepening depth first search) : 

IDDFS works by running a series of depth-limited DFS searches, gradually increasing the depth limit by 1 during each iteration.

1. First, it runs a DFS with a max depth of 1. It checks all states reachable in 1 move.If no solution is found, 
it throws away everything, resets, and runs a brand new DFS with a max depth of 2.

2. If still not solved, it resets again and runs a DFS with a max depth of 3.

3. It repeats this process until a solution is found.
*/


#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"
#include "DFSSolver.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

template<typename T, typename H>
class IDDFSSolver {

private:
    int max_search_depth;
    vector<RubiksCube::MOVE> moves;

public:
    T rubiksCube;

    IDDFSSolver(T _rubiksCube, int _max_search_depth = 7) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

//    Used DFSSolver with increasing max_search_depth
    vector<RubiksCube::MOVE> solve() {
        for (int i = 1; i <= max_search_depth; i++) {
            DFSSolver<T, H> dfsSolver(rubiksCube, i);
            moves = dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }

};


#endif //RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H