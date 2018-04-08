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
        queue<Node> nodeSudah;
        int startX;
        int startY;
        int goalX;
        int goalY;

        Node awal;
        Node finish;

        bool solved;

        void openSekitar(Node input);
        bool isNodeExist(Node input);

        void tunggu();


    public:
        Maze(); //default constructor
        Maze(vector< vector<int> > peta);

        void solve();
        bool isSolved();
        void setMaze(vector< vector<int> > peta);
        Node nodeSebelum(Node input);

};
#endif
