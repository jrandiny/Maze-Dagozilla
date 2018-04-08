#include "Node.h"
#include <cmath>
#include <iostream>

using namespace std;

Node::Node(){
    originX = -1;
    originY = -1;
    x = -1;
    y = -1;
    goalX = -1;
    goalY = -1;
    hCost = -1;
    gCost = -1;
    fCost = -1;

}

Node::Node(int originX, int originY, int x, int y, int goalX, int goalY){
    this->originX = originX;
    this->originY = originY;
    this->x = x;
    this->y = y;
    this->goalX = goalX;
    this->goalY = goalY;

    //asumsi maze hanya vertikal dan horizontal
    this->gCost = 1;

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

int Node::getX() const{
    return x;
}

int Node::getY() const{
    return y;
}

void Node::setOrigin(int x, int y){
    originX = x;
    originY = y;
}

void Node::setXY(int x, int y){
    this->x = x;
    this->y = y;
}

void Node::setGoal(int x, int y){
    goalX = x;
    goalY = y;
}

void Node::setGCost(int gCost){
    this->gCost = gCost;
}

void Node::calculate(){

    if((originX != -1) && (goalX != -1) && (x != -1)){
        //menggunakan manhattan heuristic
        hCost = abs(goalX-x) + abs(goalY-y);

        fCost = gCost + hCost;
    }else{
        cerr<<"ERROR : Node::calculate() -> origin or goal not set"<<endl;
    }


}
