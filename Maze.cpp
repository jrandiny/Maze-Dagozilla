#include <iostream>
#include <vector>
#include "Maze.h"
#include "Node.h"

using namespace std;

bool PembandingNode::operator()(const Node& node1, const Node& node2) const{
    //overide less() jadi lebih besar, agar paling atas queue paling kecil
    return node1.getFCost() > node2.getFCost();
}

Maze::Maze(){
    peta = {{0,2,1,0,3},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0}}; //default value
}

Maze::Maze(vector< vector<int> > peta){
    this->peta = peta;
}

void Maze::openSekitar(int x, int y){
    for(int i = x-1; i<=x+1;i++){
        for(int j = y-1; j<=y+1;j++){
            cout<<"posisi cek : ("<<i<<","<<j<<")"<<endl;
            //cek di dalam boks
            if((i>=0)&&(j>=0)){
                //titik origin tidak dicek
                if(!((i!=x)&&(j!=y))){
                    //cek tidak diagonal
                    if(!((i==x)&&(j==y))){
                        //cek bukan halangan
                        if(peta[i][j]!=1){
                            //cek apakah sudah ada
                            Node sementara(x,y,i,j,goalX,goalY);
                            if(!isNodeExist(sementara))
                            daftarNode.push(sementara);
                            cout<<"insert"<<endl;
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

    cout<<"cek apakah sudah ada node di : ("<<input.getX()<<","<<input.getY()<<")"<<endl;

    priority_queue<Node, vector<Node>, PembandingNode> sementara = daftarNode;

    while (!sementara.empty())
	{
		Node t =  sementara.top();
        cout << "Posisi : ("<<t.getX()<<","<<t.getY()<<")"<<endl;
		sementara.pop();
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
    cout << "start : ("<<startX<<","<<startY<<")"<<endl;
    cout << "goal : ("<<goalX<<","<<goalY<<")"<<endl;

    openSekitar(startX,startY);

    while (!daftarNode.empty())
	{
		Node t = daftarNode.top();
		cout << "origin : (" << t.getOriginX() << "," << t.getOriginY()<<")";
        cout << "| posisi : ("<<t.getX()<<","<<t.getY()<<")";
        cout << "| f cost :"<<t.getFCost()<<endl;
		daftarNode.pop();
	}


}

void Maze::setMaze(vector< vector<int> > peta){
    this->peta = peta;
}
