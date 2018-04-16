#include <iostream>
#include "Maze.h"
#include "Reader.h"
#include "Node.h"

using namespace std;

int main(){
	vector< vector<int> > data;

    cout<<"Maze Solver"<<endl<<endl;

	string input;

	Reader read;

	while(true){
		cout<<"Pilih metode input :"<<endl;
		cout<<"1. File"<<endl;
		cout<<"2. Manual"<<endl;

		cin>>input;
		if(input == "1"){
			string namaFile;
			cout<<"Masukkan nama file : ";
			cin>>namaFile;
			cout<<"Mulai membaca maze dari file : "<<namaFile<<endl;
			data = read.baca(namaFile);
			cout<<"Terbaca maze ukuran "<<data.size()<<" x "<<data[0].size()<<endl;
			break;
		}else if(input == "2"){
			cout<<"Silahkan masukkan maze"<<endl;
			data = read.bacaManual();
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
		read.tulisFile(maze1.getMaze());
    // cin>>a;
    return 0;
}
