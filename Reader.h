#ifndef READER_H
#define READER_H

#include <iostream>
#include "Maze.h"

using namespace std;

class Reader{
    private:

    public:
        Reader(); //default constructor

        Maze baca(string FileName);

};
#endif
