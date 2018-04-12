#include <iostream>
#include <vector>
#include "Maze.h"
#include "Node.h"

using namespace std;

bool PembandingNode::operator()(const Node& node1, const Node& node2) const{
    //overide less() jadi lebih besar, agar paling atas queue paling kecil
    return node1.getFCost() > node2.getFCost();
}

// Maze::Maze(){
//     peta = {{0,2,1,0,3},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0}}; //default value
//     solved = false;
// }

Maze::Maze(vector< vector<int> > peta){
    this->peta = peta;
    solved = false;
}

void Maze::openSekitar(Node input){
    int x = input.getX();
    int y = input.getY();
    for(int i = y-1; i<=y+1;i++){
        for(int j = x-1; j<=x+1;j++){
            clog<<"posisi cek : ("<<j<<","<<i<<")"<<endl;
            //cek di dalam boks
            if((i>=0)&&(i<peta.size())&&(j<peta[0].size())&&(j>=0)){
                //diagonal tidak boleh diagonal
                if(!((j!=x)&&(i!=y))){
                    //titik origin tidak dicek
                    if(!((j==x)&&(i==y))){
                        clog<<"lulus cek koordinat"<<endl;
                        //cek bukan halangan
                        if(peta[i][j]==3){
                            finish = Node(x,y,j,i,goalX,goalY,input.getGCost()+1);
                            clog<<"HORE"<<endl;
                            clog<<"posisi hore : ("<<j<<","<<i<<")"<<endl;
                            clog<<endl<<endl<<endl<<endl<<endl;
                            solved=true;
                        }
                        if(peta[i][j]!=1){
                            //cek apakah sudah ada
                            Node sementara(x,y,j,i,goalX,goalY,input.getGCost()+1);
                            if(!isNodeExist(sementara)){
                                clog<<"old g cost "<<input.getGCost()<<endl;
                                clog<<"new g cost "<<sementara.getGCost()<<endl;
                                clog<<"new h cost "<<sementara.getHCost()<<endl;
                                daftarNode.push(sementara);
                                clog<<"insert"<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Maze::isNodeExist(Node input){
    bool ketemu;

    ketemu = false;

    clog<<"cek apakah sudah ada node di : ("<<input.getX()<<","<<input.getY()<<")"<<endl;

    priority_queue<Node, vector<Node>, PembandingNode> sementara = daftarNode;

    while (!sementara.empty())
	{
		Node t =  sementara.top();
        clog << "Posisi : ("<<t.getX()<<","<<t.getY()<<")"<<endl;
		sementara.pop();
        if((t.getX()==input.getX())&&(t.getY()==input.getY())){
            ketemu = true;
        }
	}

    for (Node t : nodeSudah)
	{
        clog << "Posisi : ("<<t.getX()<<","<<t.getY()<<")"<<endl;
        if((t.getX()==input.getX())&&(t.getY()==input.getY())){
            ketemu = true;
        }
	}

    return ketemu;
}

void Maze::solve(){
    for(int i = 0; i < peta.size();i++){
        for(int j = 0; j < peta[0].size();j++){
            if(peta[i][j]==2){
                startX = j;
                startY = i;
            }
            if(peta[i][j]==3){
                goalX = j;
                goalY = i;

            }
        }
    }
    clog << "start : ("<<startX<<","<<startY<<")"<<endl;
    clog << "goal : ("<<goalX<<","<<goalY<<")"<<endl;

    awal = Node(startX,startY,startX,startY,goalX,goalY,0);
    awal.setGCost(0);

    openSekitar(awal);
    nodeSudah.push_back(awal);
    // tunggu();

    while(!solved){
        clog<<endl<<"------------------------------"<<endl;
        Node t = daftarNode.top();
        clog<<"START openSekitar FOR "<<t.getX()<<","<<t.getY()<<endl;
        nodeSudah.push_back(t);
        openSekitar(t);
        daftarNode.pop();
        if(daftarNode.empty()){
            //GAGAL
            break;
        }
        //tunggu();
    }

    clog<<endl<<endl<<endl;

    if(solved){
        clog<<"TERSELESAIKAN"<<endl;
    }else{
        clog<<"GAGAL"<<endl;
    }



}

Node Maze::nodeSebelum(Node input){

    Node sebelum;

    for (Node t : nodeSudah)
	{
        if((t.getX()==input.getOriginX())&&(t.getY()==input.getOriginY())){
            sebelum = t;
        }
	}

    return sebelum;
}

void Maze::showMove(){

    Node cari = finish;
    peta[cari.getY()][cari.getX()] = 3;
    cari = nodeSebelum(cari);
    while(true){
        cout<<"("<<cari.getX()<<","<<cari.getY()<<")"<<endl;
        peta[cari.getY()][cari.getX()] = 7;
        if(!((cari.getX()==startX)&&(cari.getY()==startY))){
            cari = nodeSebelum(cari);
        }else{
            peta[startY][startX] = 2;
            break;
        }


    }
    cout<<endl;
    for(int i=0;i<peta.size();i++){
      for(int j=0;j<peta[i].size();j++){
        switch (peta[j][i]) {
          case 1 :
            cout<< "#";
            break;
          case 0 :
            cout<< "-";
            break;
          case 2 :
            cout<< "S";
            break;
          case 3 :
            cout<< "D";
            break;
          case 7 :
            cout<< "!";
            break;
        }

      }
      cout<<endl;
    }


}

bool Maze::isSolved(){
    return solved;
}

void Maze::tunggu(){
    priority_queue<Node, vector<Node>, PembandingNode> sementara = daftarNode;

    while (!sementara.empty())
	{
		Node t = sementara.top();
		clog << "origin : (" << t.getOriginX() << "," << t.getOriginY()<<")";
        clog << "| posisi : ("<<t.getX()<<","<<t.getY()<<")";
        clog << "| f cost :"<<t.getFCost()<<endl;
		sementara.pop();
	}
    string abc;
    cin>>abc;
}

void Maze::setMaze(vector< vector<int> > peta){
    this->peta = peta;
}
