#include <QtSql>
#include <iostream>
#include <Dijkstra.h>
#include<vector>
#define INFINITY 9999
#define q2c(string) string.toStdString()
using namespace std;

Dijkstra::Dijkstra(int a)
{
    QSqlQuery qry;
    qry.exec("select COUNT(id) from ville");
    qry.next();
    numOfVertices=qry.value(0).toInt();
    predecessor=new int[numOfVertices];
    distance=new int[numOfVertices];
    mark=new bool[numOfVertices];
    adjMatrix=new int*[numOfVertices];
    for(int i=0;i<numOfVertices;i++)
    {
        adjMatrix[i]=new int[numOfVertices];
        for(int j=0;j<numOfVertices;j++)
            adjMatrix[i][j]=9999;
    }
    source=a;
}
void Dijkstra::read(){
    QSqlQuery qry;
    qry.exec("select id_d,id_a,distance from distance");
    while(qry.next())
    {
        adjMatrix[qry.value(0).toInt()][qry.value(1).toInt()]=qry.value(2).toInt();
    }
}
void Dijkstra::initialize(){
    for(int i=0;i<numOfVertices;i++) {
        mark[i] = false;
        predecessor[i] = -1;
        distance[i] = INFINITY;
    }
    distance[source]= 0;
}
int Dijkstra::getClosestUnmarkedNode(){
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    for(int i=0;i<numOfVertices;i++) {
        if((!mark[i]) && ( minDistance >= distance[i])) {
            minDistance = distance[i];
            closestUnmarkedNode = i;
        }
    }
    return closestUnmarkedNode;
}
void Dijkstra::calculateDistance(){
    initialize();
    int closestUnmarkedNode;
    int count = 0;
    while(count < numOfVertices) {
        closestUnmarkedNode = getClosestUnmarkedNode();
        mark[closestUnmarkedNode] = true;
        for(int i=0;i<numOfVertices;i++) {
            if((!mark[i]) && (adjMatrix[closestUnmarkedNode][i]>0) ) {
                if(distance[i] > distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i]) {
                    distance[i] = distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
}
void Dijkstra::printPath(int node,vector<int> &V)
{

    if(node == source)
        V.push_back(node);
    else
    {
        printPath(predecessor[node],V);
        V.push_back(node);
    }
}
int Dijkstra::getdistance(int i)
{
    return  distance[i];
}
