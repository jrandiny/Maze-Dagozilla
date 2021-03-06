#ifndef NODE_H
#define NODE_H

class Node{
    private:
        int hCost;
        int gCost;
        int fCost;
        int originX;
        int originY;
        int x;
        int y;
        int goalX;
        int goalY;

        void calculate();

    public:
        Node();
        Node(int originX, int originY, int x, int y, int goalX, int goalY, int gCost);

        int getGCost() const;
        int getHCost() const;
        int getFCost() const;
        int getOriginX() const;
        int getOriginY() const;
        int getX() const;
        int getY() const;

        void setOrigin(int x, int y);
        void setXY(int x, int y);
        void setGoal(int x, int y);
        void setGCost(int gCost);


};
#endif
