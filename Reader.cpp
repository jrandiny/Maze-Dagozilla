#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
    clog<<baris<<" "<<kolom;

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
            clog<<a[i][j];
            //cout<<x;
        }
        clog<<endl;
    }

    vector<vector<int> > b(baris);
    for ( int i = 0 ; i < baris ; i++ ){
        b[i].resize(kolom);
    }

    for(int i=0;i<kolom;i++){
        for(int j=0;j<baris;j++){
            b[j][i] = a[j][i];
            clog<<b[j][i];
        }
        clog<<endl;
    }

    delete a;

    return b;
}

vector< vector<int> > Reader::bacaManual(){
  int baris,kolom;
  int** a;

  cout <<"Masukan Jumlah Baris :";
  cin >> baris;
  cout << "Masukan jumlah kolom :";
  cin >> kolom;

  a = new int*[baris];
  for(int j = 0;j<baris;j++){
    a[j] = new int[kolom];
  }

  string inputBaris;

  for(int i=0;i<baris;i++){
    cin >> inputBaris;
    while(inputBaris.length()!=kolom){
      cout<<"Ulangin Input Baris!!"<<endl;
      cin >> inputBaris;
    }
    for (int j=0;j<kolom;j++){
      switch (inputBaris[j]) {
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
    }
  }

  vector<vector<int> > b(baris);
  for ( int i = 0 ; i < baris ; i++ ){
    b[i].resize(kolom);
  }

  for(int i=0;i<kolom;i++){
    for(int j=0;j<baris;j++){
      b[j][i] = a[i][j];
      cout<<b[j][i];
    }
    cout<<endl;
  }

return b;
}

void Reader::tulisFile(vector< vector<int> > hasil){
  ofstream tulis;
  tulis.open("hasil.txt");

  for (int i=0;i<hasil.size();i++){
    for (int j=0;j<hasil[i].size();j++){

      switch (hasil[j][i]) {
        case 1 :
          tulis << '#';
          break;
        case 0 :
          tulis << '-';
          break;
        case 2 :
          tulis << 'S';
          break;
        case 3 :
          tulis << 'D';
          break;
        case 7 :
          tulis<< "!";
          break;
        }


    }
    tulis << endl;
  }
}
