#include <iostream>
#include <vector>
#include "Maze.h"
#include "Node.h"

using namespace std;

bool PembandingNode::operator()(const Node& node1, const Node& node2) const{
    return node1.getFCost() < node2.getFCost();
}

Maze::Maze(){
    peta = {{0,0,0},{1,1,1},{2,2,2}}; //default value
}

Maze::Maze(vector< vector<int> > peta){
    this->peta = peta;
}

void Maze::solve(){

}

void setMaze(Maze Input){

}
