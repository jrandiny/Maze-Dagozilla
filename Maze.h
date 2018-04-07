#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>

using namespace std;

class Maze{
    private:
        vector< vector<int> > peta;

    public:
        Maze(); //default constructor

        void solve();
        void setMaze(Maze Input);

};
#endif
