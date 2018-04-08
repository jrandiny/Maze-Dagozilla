#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "Node.h"
#include <queue>

using namespace std;

class PembandingNode{
    public:
        bool operator()(const Node& node1, const Node& node2) const;

};

class Maze{
    private:
        vector< vector<int> > peta;
        priority_queue<Node, vector<Node>, PembandingNode> daftarNode;


    public:
        Maze(); //default constructor
        Maze(vector< vector<int> > peta);

        void solve();
        void setMaze(Maze Input);

};
#endif
