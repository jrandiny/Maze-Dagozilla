#include <iostream>
#include "Maze.h"
#include "Reader.h"
#include "Node.h"

using namespace std;

int main(){
	vector< vector<int> > data;

    cout<<"Maze Solver"<<endl<<endl;

	cout<<"Pilih metode input :"<<endl;
	cout<<"1. File"<<endl;
	cout<<"2. Manual"<<endl;

	int input;

	Reader read;

	while(true){
		cin>>input;
		switch(input){
			case 1:{
				string namaFile;
				cout<<"Masukkan nama file : ";
				cin>>namaFile;
				cout<<"Mulai membaca maze dari file : "<<namaFile<<endl;
				data = read.baca(namaFile);
				cout<<"Terbaca maze ukuran "<<data.size()<<" x "<<data[0].size()<<endl;
				break;
			}
			case 2:{
				cout<<"Silahkan masukkan maze"<<endl;
				data = read.baca();
				break;
			}
			default:{
				input = 0;
				break;
			}
		}

		if(input != 0){
			break;
		}
	}




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
<<<<<<< HEAD
		read.tulisFile(maze1.getMaze());
    cin>>a;
=======
    // cin>>a;
>>>>>>> 209076ee9cbccc7666cd4043aa5c0d3a4ead237f
    return 0;
}
