#include <iostream>
#include "Maze.h"
#include "Reader.h"
#include "Node.h"

using namespace std;

int main(){
	int a;
	vector< vector<int> > data;

    cout<<"Maze Solver"<<endl<<endl;;

	Reader read;
	cout<<"Mulai membaca maze dari file"<<endl;
	data = read.baca("data.txt");
	cout<<"Terbaca maze ukuran "<<data.size()<<" x "<<data[0].size()<<endl;

	cout<<endl;
	cout<<"Mencoba menyelesaikan"<<endl;

	Maze maze1(data);
    maze1.solve();
    if(maze1.isSolved()){
       cout<<"Terselesaikan"<<endl;
       maze1.showMove();
    }else{
       cout<<"Tidak terselesaikan"<<endl;
    }
    // cin>>a;
    return 0;
}
