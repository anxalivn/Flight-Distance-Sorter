using namespace std;
#include "city.h"
#include "graph.h"
#include<iomanip>


template <class T>
Graph<T>::Graph(int a1, int a2)
{
	this->isDirected = false;
	this->isWeighted = false;

	if (a1 == DIRECTED || a2==DIRECTED) {
		this->isDirected = true;
	}
	if (a1 == WEIGHTED || a2 == WEIGHTED) {
		this->isWeighted = true;
	}
	
	for (int i = 0; i < 100; i++) {
		Deleted[i] = false;
		for (int j = 0; j < 100; j++) {
			if (i == j) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = -1;
			}
		}
	}
	numVertices = 0;
	numEdges = 0;
	index = 0;
}
template <class T>
Graph<T>::Graph(int a1)
{
	this->isDirected = false;
	this->isWeighted = false;

	if (a1 == DIRECTED) {
		this->isDirected = true;
	}
	else if (a1 == WEIGHTED) {
		this->isWeighted = true;
	}

	for (int i = 0; i < 100; i++) {
		Deleted[i] = false;
		for (int j = 0; j < 100; j++) {
			if (i == j) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = -1;
			}
		}
	}
	numVertices = 0;
	edgeCount = 0;
	index = 0;

}
template <class T>
Graph<T>::Graph()
{
	this->isDirected = false;
	this->isWeighted = false;

	for (int i = 0; i < 100; i++) {
		Deleted[i] = false;
		for (int j = 0; j < 100; j++) {
			if (i == j) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = -1;
			}
		}
	}
	numVertices = 0;
	edgeCount = 0;
	index = 0;

}

template <class T>
bool Graph<T>::isEmpty()
{
	if (numVertices == 0)
		return true;
	else
		return false;
}

template <class T>
void Graph<T>::insertVertex(T city1) {
	int ind1 = findIndex(city1);
	if(ind1==-1){
		CityList[index] = city1;
		index += 1;
		numVertices += 1;
	}
	else {
		throw logic_error("exception - duplicate vertex");
	}
}

template <class T>
bool Graph<T>::isFull() {
	if (numVertices == 100)
		return true;
	else
		return false;
}

template <class T>
void Graph<T>::insertEdge(T city1, T city2, int weight) {
	int indc1 = -1;
	int indc2 = -1;
	for (int i = 0; i < index; i++){
		if (this->CityList[i] == city1) {
			indc1 = i;
		}
		if (this->CityList[i] == city2) {
			indc2 = i;
		}
	}

	if (indc1 >= 0 && indc2 >= 0) {
		if (isWeighted == true) {
			if (this->matrix[indc1][indc2] != weight) {
				this->matrix[indc1][indc2] = weight;
			}
			else {
				throw logic_error("exception - duplicate edge");
			}
			this->numEdges += 1;
			if (isDirected == false) {
				this->matrix[indc2][indc1] = weight;
			}
			
		}
	}
}

template <class T>
void Graph<T>::dump() {
	cout << "dumping graph:  ";
	if (isDirected)
		cout << "DIRECTED  ";
	else
		cout << "UNDIRECTED  ";
	if (isWeighted)
		cout << "WEIGHTED  ";
	else
		cout << "UNWEIGHTED  ";
	cout << "vertices:" << this->numVertices;
	cout << "   edges:" << this->numEdges<<endl;
	cout << "VERTEX          ADJACENT VERTICES" << endl;
	cout << "--------------   ----------------------------" << endl;

	for (int i = 0; i < this->index; i++) {
		if (this->Deleted[i] == false) {
			cout << this->CityList[i] << setw(10) << " ";
			for (int j = 0; j < index; j++) {
				if (matrix[i][j] > 0) {
					cout << this->CityList[j] << "(";
					cout << matrix[i][j];
					cout << ") ";
				}
			}
		}
		cout << endl;
	}


}

template <class T>
bool Graph<T>::isAdjacentTo(T city1, T city2) {
	int ind1 = this->findIndex(city1);
	int ind2 = this->findIndex(city2);
	if (ind1 >= 0 && ind2 >= 0) {
		if (this->matrix[ind1][ind2] >= 0)
			return true;
	}
	return false;


	return true;
}
template <class T>
int Graph<T>::edgeWeight(T city1, T city2) {
	int ind1 = this->findIndex(city1);
	int ind2 = this->findIndex(city2);
	if (ind1 >= 0 && ind2 >= 0) {
		return this->matrix[ind1][ind2];
	}
	return -1;
}

template <class T>
void Graph<T>::deleteEdge(T City1, T City2) {
	
	int ind1 = this->findIndex(City1);
	int ind2 = this->findIndex(City2);

	if (ind1 >= 0 && ind2 >= 0) {
		this->matrix[ind1][ind2] = -1;
		this->numEdges -= 1;
		if (isDirected == false) {
			this->matrix[ind2][ind1] = -1;
		}
	}
}


template <class T>
void Graph<T>::deleteVertex(T cityN) {
	int ind1 = this->findIndex(cityN);
	if (ind1 == -1) {
		throw logic_error("exception - vertex doesn't exist");
	}
	else if (ind1 >= 0) {
		this->Deleted[ind1] = true;
		numVertices -= 1;
		for (int i = 0; i < index; i++)
		{
			if(ind1!=i){
				this->matrix[ind1][i] = -1;
				this->matrix[i][ind1] = -1;
			}
		}

	}

}

template <class T>
int Graph<T>::vertexCount() {

	return this->numVertices;
}

template <class T>
int Graph<T>::edgeCount() {

	return this->numEdges;
}

template <class T>
void Graph<T>::destroy() {
	for (int i = 0; i < 100; i++) {
		Deleted[i] = false;
		for (int j = 0; j < 100; j++) {
			if (i == j) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = -1;
			}
		}
	}
	this->numVertices = 0;
	this->index = 0;
	this->numEdges = 0;
}

template <class T>
int Graph<T>::findIndex(T city1) {

	for (int i = 0; i < index; i++) {
		if (this->CityList[i] == city1) {
			if (this->Deleted[i] == false) {
				return i;
			}
		}
	}
	return -1;
}

void test()
{
	Graph<City> graph(1,1);
	graph.isEmpty();
	City Seattle("Seattle");
	City SanFrancisco("San Francisco");
	graph.insertVertex(Seattle);
	graph.isFull();
	graph.insertEdge(Seattle, SanFrancisco, 0);
	graph.dump();
	graph.isAdjacentTo(SanFrancisco, Seattle);
	graph.edgeWeight(Seattle, SanFrancisco);
	graph.deleteEdge(SanFrancisco, Seattle);
	graph.deleteVertex(Seattle);
	graph.vertexCount();
	graph.edgeCount();
	graph.destroy();
}
