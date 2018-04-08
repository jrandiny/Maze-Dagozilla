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
    solved = false;
}

Maze::Maze(vector< vector<int> > peta){
    this->peta = peta;
    solved = false;
}

void Maze::openSekitar(Node input){
    int x = input.getX();
    int y = input.getY();
    for(int i = y-1; i<=y+1;i++){
        for(int j = x-1; j<=x+1;j++){
            cout<<"posisi cek : ("<<j<<","<<i<<")"<<endl;
            //cek di dalam boks
            if((i>=0)&&(i<peta.size())&&(j<peta[0].size())&&(j>=0)){
                //diagonal tidak boleh diagonal
                if(!((j!=x)&&(i!=y))){
                    //titik origin tidak dicek
                    if(!((j==x)&&(i==y))){
                        cout<<"lulus cek koordinat"<<endl;
                        //cek bukan halangan
                        if(peta[i][j]==3){
                            finish = Node(x,y,j,i,goalX,goalY,input.getGCost()+1);
                            cout<<"HORE"<<endl;
                            cout<<"posisi hore : ("<<j<<","<<i<<")"<<endl;
                            cout<<endl<<endl<<endl<<endl<<endl;
                            solved=true;
                        }
                        if(peta[i][j]!=1){
                            //cek apakah sudah ada
                            Node sementara(x,y,j,i,goalX,goalY,input.getGCost()+1);
                            if(!isNodeExist(sementara)){
                                cout<<"old g cost "<<input.getGCost()<<endl;
                                cout<<"new g cost "<<sementara.getGCost()<<endl;
                                cout<<"new h cost "<<sementara.getHCost()<<endl;
                                daftarNode.push(sementara);
                                cout<<"insert"<<endl;
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

    queue<Node> sementaraSudah = nodeSudah;

    while (!sementaraSudah.empty())
	{
		Node t =  sementaraSudah.front();
        cout << "Posisi : ("<<t.getX()<<","<<t.getY()<<")"<<endl;
		sementaraSudah.pop();
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

    awal = Node(startX,startY,startX,startY,goalX,goalY,0);
    awal.setGCost(0);

    openSekitar(awal);
    nodeSudah.push(awal);
    // tunggu();

    while(!solved){
        cout<<endl<<"------------------------------"<<endl;
        Node t = daftarNode.top();
        cout<<"START openSekitar FOR "<<t.getX()<<","<<t.getY()<<endl;
        nodeSudah.push(t);
        openSekitar(t);
        daftarNode.pop();
        //tunggu();
    }

    cout<<endl<<endl<<endl;
    cout<<"TERSELESAIKAN"<<endl;

    cout<<"LIAT CARA"<<endl;

    Node cari = finish;

    while(true){
        cout<<"("<<cari.getX()<<","<<cari.getY()<<")"<<endl;
        if(!((cari.getX()==startX)&&(cari.getY()==startY))){
            cari = nodeSebelum(cari);
        }else{
            break;
        }

    }

}

Node Maze::nodeSebelum(Node input){
    queue<Node> sementaraSudah = nodeSudah;

    Node sebelum;

    while (!sementaraSudah.empty())
	{
		Node t =  sementaraSudah.front();
		sementaraSudah.pop();
        if((t.getX()==input.getOriginX())&&(t.getY()==input.getOriginY())){
            sebelum = t;
        }
	}

    return sebelum;
}

bool Maze::isSolved(){
    return solved;
}

void Maze::tunggu(){
    priority_queue<Node, vector<Node>, PembandingNode> sementara = daftarNode;

    while (!sementara.empty())
	{
		Node t = sementara.top();
		cout << "origin : (" << t.getOriginX() << "," << t.getOriginY()<<")";
        cout << "| posisi : ("<<t.getX()<<","<<t.getY()<<")";
        cout << "| f cost :"<<t.getFCost()<<endl;
		sementara.pop();
	}
    string abc;
    cin>>abc;
}

void Maze::setMaze(vector< vector<int> > peta){
    this->peta = peta;
}
