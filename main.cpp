#include <bits/stdc++.h>
// Included models and solvers
// #include "Model/RubiksCube3dArray.cpp"
#include "PatternDatabases/CornerDBMaker.h" 
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"

using namespace std;
using namespace std::chrono;

// Helper function to print move sequences cleanly
void printMoves(const vector<RubiksCube::MOVE>& moves, const RubiksCube3dArray& cube) {
    for (auto m : moves) {
        cout << cube.getMove(m) << " ";
    }
    cout << "\n";
}

int main() {
    string dbFileName = "cornerDatabase.db";
    
    cout << "========================================\n";
    cout << "      RUBIK'S CUBE SOLVER BENCHMARK     \n";
    cout << "========================================\n\n";

    //After generating the database once you can comment out these lines.
    // // 1. Generate the Corner Database
    // cout << "[*] Initializing Database Generation...\n";
    // auto db_start = high_resolution_clock::now();
    
    // // Seed with 0xFF (255) for unvisited states
    // CornerDBMaker dbMaker(dbFileName, 0xFF); 
    // dbMaker.bfsAndStore();
    
    // auto db_end = high_resolution_clock::now();
    // auto db_duration = duration_cast<milliseconds>(db_end - db_start);
    // cout << "[+] Database created successfully in " << db_duration.count() << " ms.\n\n";

    // 2. Initialize and Scramble the Cube
    RubiksCube3dArray cube;
    cout << "[*] Scrambling the cube (5 random moves)...\n";
    
    // Using a 5-move scramble. (DFS/BFS will choke on deeper scrambles)
    vector<RubiksCube::MOVE> scramble = cube.randomShuffleCube(5);
    
    cout << "Scramble Sequence: ";
    printMoves(scramble, cube);
    cout << "\nJumbled Cube State:\n";
    cube.print();
    cout << "----------------------------------------\n\n";

    // 3. DFS Solver
    cout << "[*] Running DFS Solver...\n";
    DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8); // Max depth 8
    auto start = high_resolution_clock::now();
    vector<RubiksCube::MOVE> dfs_moves = dfsSolver.solve();
    auto end = high_resolution_clock::now();
    
    cout << "    -> Moves taken : " << dfs_moves.size() << "\n";
    cout << "    -> Solution    : "; printMoves(dfs_moves, cube);
    cout << "    -> Time taken  : " << duration_cast<milliseconds>(end - start).count() << " ms\n\n";

    // 4. BFS Solver
    cout << "[*] Running BFS Solver...\n";
    BFSSolver<RubiksCube3dArray, Hash3d> bfsSolver(cube);
    start = high_resolution_clock::now();
    vector<RubiksCube::MOVE> bfs_moves = bfsSolver.solve();
    end = high_resolution_clock::now();
    
    cout << "    -> Moves taken : " << bfs_moves.size() << "\n";
    cout << "    -> Solution    : "; printMoves(bfs_moves, cube);
    cout << "    -> Time taken  : " << duration_cast<milliseconds>(end - start).count() << " ms\n\n";

    // 5. IDDFS Solver
    cout << "[*] Running IDDFS Solver...\n";
    IDDFSSolver<RubiksCube3dArray, Hash3d> iddfsSolver(cube, 8); // Max depth 8
    start = high_resolution_clock::now();
    vector<RubiksCube::MOVE> iddfs_moves = iddfsSolver.solve();
    end = high_resolution_clock::now();
    
    cout << "    -> Moves taken : " << iddfs_moves.size() << "\n";
    cout << "    -> Solution    : "; printMoves(iddfs_moves, cube);
    cout << "    -> Time taken  : " << duration_cast<milliseconds>(end - start).count() << " ms\n\n";

    // 6. IDA* Solver
    cout << "[*] Running IDA* Solver...\n";
    IDAstarSolver<RubiksCube3dArray, Hash3d> idastarSolver(cube, dbFileName);
    start = high_resolution_clock::now();
    vector<RubiksCube::MOVE> idastar_moves = idastarSolver.solve();
    end = high_resolution_clock::now();
    
    cout << "    -> Moves taken : " << idastar_moves.size() << "\n";
    cout << "    -> Solution    : "; printMoves(idastar_moves, cube);
    cout << "    -> Time taken  : " << duration_cast<milliseconds>(end - start).count() << " ms\n\n";

    cout << "========================================\n";
    cout << "           ALL TESTS COMPLETED          \n";
    cout << "========================================\n";

    return 0;
}