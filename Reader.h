#ifndef READER_H
#define READER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Maze.h"

using namespace std;

class Reader{
    private:
          vector< vector<int> > b;
    public:
        Reader(); //default constructor

        vector< vector<int> > baca(string FileName);
        vector< vector<int> > baca();

};
#endif
