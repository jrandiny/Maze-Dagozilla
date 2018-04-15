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
<<<<<<< HEAD
        vector< vector<int> > bacaManual();
        void tulisFile(vector< vector<int> > hasil);
=======
        vector< vector<int> > baca();

>>>>>>> 209076ee9cbccc7666cd4043aa5c0d3a4ead237f
};
#endif
