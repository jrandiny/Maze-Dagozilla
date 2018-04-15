#ifndef READER_H
#define READER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Maze.h"

using namespace std;

class Reader{
    private:

    public:
        Reader(); //default constructor

        vector< vector<int> > baca(string FileName);
        vector< vector<int> > bacaManual();
        void tulisFile(vector< vector<int> > hasil);
};
#endif
