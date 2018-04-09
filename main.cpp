#include <iostream>
#include "Maze.h"
// #include "Reader.h"
#include "Node.h"

using namespace std;

int main(){
    cout<<"Maze Solver"<<endl;
    Maze maze1;
    maze1.solve();
    if(maze1.isSolved()){
        cout<<"Terselesaikan"<<endl;
        maze1.showMove();
    }else{
        cout<<"Tidak terselesaikan"<<endl;
    }

    return 0;
}
