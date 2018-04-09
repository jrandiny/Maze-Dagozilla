#include <iostream>
#include "Maze.h"
// #include "Reader.h"
#include "Node.h"

using namespace std;

int main(){
	int a;
    cout<<"Maze Solver"<<endl;
    Maze maze1;
    maze1.solve();
    if(maze1.isSolved()){
        cout<<"Terselesaikan"<<endl;
        maze1.showMove();
    }else{
        cout<<"Tidak terselesaikan"<<endl;
    }
    cin>>a;
    return 0;
}
