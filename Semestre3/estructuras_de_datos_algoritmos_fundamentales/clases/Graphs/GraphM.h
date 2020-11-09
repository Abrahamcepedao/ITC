#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
class GraphM{
    private:
        vector< vector<T> >  adjMatrix;
        vector<T> vertices;
        int qtyVertices;
        int qtyEdges;
        int findVertex(T vertex);
    public:
        GraphM(vector< vector<T> > list, int qtyVertices, int qtyEdges);
        void print();
};

template <class T>
GraphM<T>::GraphM(vector< vector<T> > list, int qtyVertices, int qtyEdges){
    this->qtyVertices = qtyVertices;
    this->qtyEdges = qtyEdges;
    int source = 0, target = 1;
    for(int i = 0; i < qtyVertices; i++){
        vector<bool> temp;
        for(int j = 0; i < qtyVertices; j++){
            temp.push_back(false);
        }
        adjMatrix.push_back(temp);
    }
    for(vector<T> edge: list){
        T temp = edge[source];
        int pos = findVertex(temp);
        if(pos < 0){
            vertices.push_back(temp);
        }
        temp = edge[target];
        pos = findVertex(temp);
        if(pos < 0){
            vertices.push_back(temp);
        }
    }
    sort(vertices.begin(), vertices.end());
    for(vector<T> edge: list){
        int posSource = findVertex(edge[source]);
        int posTarget = findVertex(edge[target]);
        adjMatrix[posSource][posTarget] = true;
    }
}

template<class T>
int GraphM<T>::findVertex(T vertex){
    typename vector<int>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
    return it != vertices.end() ? (it - vertices.begin()) : -1;
}

template<class T>
void GraphM<T>::print(){
    cout << "   ";
    for(T vertex: vertices){
        cout << vertex << " ";
    }
    cout << "\n";
    for(int i = 0; i < qtyVertices; i++){
        cout << vertices[i] << " ";
        for(int j = 0; j < qtyVertices; j++){
            cout << (adjMatrix[i][j] ? "T " : << "F ");
        }
        cout << "\n";
    }
}
