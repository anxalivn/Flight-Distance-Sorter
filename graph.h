#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string>
using namespace std;
enum State { DIRECTED = 1, WEIGHTED = 2 };
template <class T>
class Graph
{
public:
	Graph(int, int);
	Graph(int);
	Graph();
	bool isEmpty();
	void insertVertex(T);
	bool isFull();
	void insertEdge(T, T, int);
	void dump();
	bool isAdjacentTo(T,T);
	int edgeWeight(T,T);
	void deleteEdge(T, T);
	void deleteVertex(T);
	int vertexCount();
	int edgeCount();
	void destroy();
	int findIndex(T);
private:
	
	int matrix[100][100];
	T CityList[100];
	bool Deleted[100];
	int numVertices;
	int numEdges;
	int index = 0;
	bool isDirected;
	bool isWeighted;
};
#endif