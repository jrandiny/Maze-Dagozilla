#include <iostream>
#include "Maze.h"
// #include "Reader.h"
#include "Node.h"

using namespace std;

int main(){
    Maze maze1;
    maze1.solve();
    if(maze1.isSolved()){
        maze1.showMove();
    }else{
        cout<<"Tidak terselesaikan"<<endl;
    }

    return 0;
}
