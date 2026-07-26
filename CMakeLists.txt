# 1. Minimum Version and Project Name
cmake_minimum_required(VERSION 3.20)
project(rubiks_cube_solver)

# 2. Set C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

# 3. Add Include Directories
include_directories(Model)
include_directories(${CMAKE_SOURCE_DIR})

# 4. Compile the Executable
add_executable(rubiks_cube_solver
        main.cpp 
        Model/RubiksCube.cpp
        Model/RubiksCube.h
        Model/RubiksCube3dArray.cpp 
        Model/RubiksCube1dArray.cpp 
        
        Solver/DFSSolver.h 
        Solver/BFSSolver.h 
        Solver/IDDFSSolver.h 
        Solver/IDAstarSolver.h 
        PatternDatabases/NibbleArray.cpp 
        PatternDatabases/NibbleArray.h 
        PatternDatabases/PatternDatabase.cpp 
        PatternDatabases/PatternDatabase.h 
        PatternDatabases/PermutationIndexer.h 
        PatternDatabases/CornerPatternDatabase.cpp 
        PatternDatabases/CornerPatternDatabase.h 
        PatternDatabases/CornerDBMaker.cpp 
        PatternDatabases/CornerDBMaker.h 
        PatternDatabases/math.cpp 
        PatternDatabases/math.h
)