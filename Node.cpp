#include "Node.h"
#include <cmath>
#include <iostream>

using namespace std;

Node::Node(){
    originX = -1;
    originY = -1;
    goalX = -1;
    goalY = -1;
    hCost = -1;
    gCost = -1;
    fCost = -1;

}

Node::Node(int originX, int originY, int goalX, int goalY){
    this->originX = originX;
    this->originY = originY;
    this->goalX = goalX;
    this->goalY = goalY;

    //asumsi maze hanya vertikal dan horizontal
    this->gCost = 1;

    calculate();
}

Node::Node(int originX, int originY, int goalX, int goalY, int gCost){
    this->originX = originX;
    this->originY = originY;
    this->goalX = goalX;
    this->goalY = goalY;

    this->gCost = gCost;

    calculate();
}

int Node::getGCost() const{
    return gCost;
}

int Node::getHCost() const{
    return hCost;
}

int Node::getFCost() const{
    return fCost;
}

int Node::getOriginX() const{
    return originX;
}

int Node::getOriginY() const{
    return originY;
}

void Node::setOrigin(int x, int y){
    originX = x;
    originY = y;
    if((goalX != -1) && (gCost != -1)){
        calculate();
    }
}

void Node::setGoal(int x, int y){
    goalX = x;
    goalY = y;
    if((originX != -1) && (gCost != -1)){
        calculate();
    }
}

void Node::setGCost(int gCost){
    this->gCost = gCost;
}

void Node::calculate(){

    if((originX != -1) && (goalX != -1)){
        //menggunakan manhattan heuristic
        hCost = abs(goalX-originX) + abs(goalY-originY);

        fCost = gCost + hCost;
    }else{
        cerr<<"ERROR : Node::calculate() -> origin or goal not set"<<endl;
    }


}
