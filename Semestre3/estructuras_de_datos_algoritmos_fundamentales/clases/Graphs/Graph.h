#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
class Graph{
    private: 
        vector< vector<T> > adjList;
        vector<T> vertices;
        int qtyVertices;
        int qtyEdges;
        int findVertex(T vertex);
    public: 
        Graph(vector< vector<T> > adjList, int qtyVertices, int qtyEdges);
        void print();
};

template <class T>
Graph<T>::Graph(vector< vector<T> > list, int qtyVertices, int qtyEdges){
    this->qtyVertices = qtyVertices;
    this->qtyEdges = qtyEdges;
    int source = 0, target = 1;
    for(vector<T> edge: list){
        T temp = edge[source];
        int pos = findVertex(temp);
        if(pos >= 0){
            adjList[pos].push_back(edge[target]);
        } else{
            vertices.push_back(temp);
            adjList.push_back(edge);
        }
    }
    if(vertices.size() < qtyVertices){
        for(vector<T> edge: list){
            T temp = edge[target];
            int pos = findVertex(temp);
            if(pos < 0){
                vertices.push_back(temp);
                vector<T> tempVertex;
                tempVertex.push_back(temp);
                adjList.push_back(tempVertex);
            }
        }
    }
}

template<class T>
int Graph<T>::findVertex(T vertex){
    typename vector<int>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
    return it != vertices.end() ? (it - vertices.begin()) : -1;
}

template<class T>
void Graph<T>::print(){
    for(vector<T> vertex: adjList){
        for(T node: vertex){
            cout << node << " ";
        }
        cout << "\n";
    }
}