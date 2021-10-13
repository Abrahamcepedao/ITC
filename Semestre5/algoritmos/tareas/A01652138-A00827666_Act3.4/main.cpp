//Actividad 3.4 Implementación de "Graph coloring"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
//#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//safe
//input: v (número de vertice), graph (todo el grafo), colors (dominio de colores), c (color a revisar)
//output: true/false si el color es válido para el vertice
//O(N)
bool safe(int v, vector< vector<bool> > graph, vector<int> colors, int c){
    for(int i = 0; i < graph[0].size(); i++) if (graph[v][i] && c == colors[i]) return false;
    return true;
}

//util
//input: graph (todo el grafo), colors (dominio de colores),  v (vertice)
//output: true/false si se puede colorear el grafo
//O(m^V) (m = cantidad de colores; V = cantidad de vertices)
bool util(vector< vector<bool> > graph, vector<int> &colors, int v){
    if (v == graph[0].size()) return true;
 
    for(int i = 1; i <= graph[0].size(); i++){
        if (safe(v, graph, colors, i)){
            colors[v] = i;
 
            if (util(graph, colors, v + 1) == true) return true;
 
            colors[v] = 0;
        }
    }
    return false;
}

//print
//input: colors (vertices coloreados)
//output: vertices coloreados
//O(V) 
void print(vector<int> colors){
    cout << "Solución: \n";
    for (int i = 0; i < colors.size(); i++) cout << "Node: " << i << ", Assigned Color: " << (colors[i]-1) << "\n";
    cout << "\n";
}

//colorGraph
//input: graph (grafo)
//output: vertices coloreados o "no hay solucion"
//O(m^V)
void colorGraph(vector< vector<bool> > graph){
    vector<int> colors(graph[0].size(), 0);
 
    if(!util(graph, colors, 0)) {
        cout << "No hay solucion";
     } else {
         print(colors);
     }
}

int main(){
	int n, num;
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementación de Graph coloring\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout<<"Ingresa el valor de n: >\n"; cin >> n;
    vector< vector<bool> > graph(n, vector<bool>(n, 0));
    
    //leer grafo
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            graph[i][j] = num == 1;
        }    
    }

    //colorear grafo
    colorGraph(graph);

    return(0);
}