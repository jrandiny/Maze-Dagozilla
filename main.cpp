#include <iostream>
#include "Maze.h"
#include "Reader.h"
#include "Node.h"

using namespace std;

int main(){
	int a;
	vector< vector<int> > data;
    cout<<"Maze Solver"<<endl;
		Reader read;
		data = read.baca("data.txt");
    Maze maze1(data);
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
