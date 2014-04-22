#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include<vector>
using namespace std;

class Dijkstra{
    private:
        int** adjMatrix;
        int* predecessor,*distance;
        bool* mark; //keep track of visited node
        int source;
        int numOfVertices;
    public:
        Dijkstra(int=0);
        void read();
        void initialize();
        int getClosestUnmarkedNode();
        void calculateDistance();
        void printPath(int,vector<int> &);
        int getdistance(int);
};
#endif // DIJKSTRA_H
