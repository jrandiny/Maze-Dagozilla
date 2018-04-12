#include <iostream>
#include <fstream>
#include <vector>
#include "Reader.h"
#include "Maze.h"

using namespace std;

Reader::Reader(){

}

vector< vector<int> > Reader::baca(string FileName){
  int baris,kolom;
  char x;
  int** a;




  baris = 0; kolom = 0;
  ifstream baca;
  baca.open("data.txt");
  baca>>baris>>kolom;
  cout<<baris<<" "<<kolom;


  a = new int*[baris];
  for(int j = 0;j<baris;j++){
    a[j] = new int[kolom];
  }


  for(int j=0;j<kolom;j++){
    for(int i=0;i<baris;i++){
    baca>>x;
    switch (x) {
      case '#' :
        a[i][j] = 1;
        break;
      case '-' :
        a[i][j] = 0;
        break;
      case 'S' :
        a[i][j] = 2;
        break;
      case 'D' :
        a[i][j] = 3;
        break;
    }
    cout<<a[i][j];
    //cout<<x;
    }
    cout<<endl;
    }

    vector<vector<int> > b(baris);
    for ( int i = 0 ; i < baris ; i++ ){
      b[i].resize(kolom);
}

    for(int i=0;i<kolom;i++){
      for(int j=0;j<baris;j++){
        b[j][i] = a[j][i];
        cout<<b[j][i];
      }
      cout<<endl;
    }



    return b;
}
