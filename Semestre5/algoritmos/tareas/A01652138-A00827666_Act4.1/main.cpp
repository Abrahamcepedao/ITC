//Actividad 4.1 Implementación Intersección y proximidad aplicando geometría computacional.
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
//#include<bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

//Direction
//input: the coordinates of three points
//output: direction of the points
//complexity O(1)
int direction(int x1, int y1, int x2, int y2, int x3, int y3){
    int val = (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1);
    if (val == 0)
        return 0;
    return (val > 0)? 1: 2;
}

//onSegment
//input: the coordinates of three points
//output: true/false  (depending if the points are on segment)
//complexity O(1)
bool onSegment(int x1, int y1, int x2, int y2, int x3, int y3){
    if (x2 <= max(x1, x3) && x2 >= min(x1, x3) && y2 <= max(y1, y3) && y2 >= min(y1, y3))
        return true;
    return false;
}

//segmentIntersection
//input: the coordinates of four points
//output: true/false  (depending if the points intersect)
//complexity O(1)
bool segmentIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int d1, d2, d3, d4;
    d1 = direction(x3, y3, x4, y4, x1, y1);
    d2 = direction(x3, y3, x4, y4, x2, y2);
    d3 = direction(x1, y1, x2, y2, x3, y3);
    d4 = direction(x1, y1, x2, y2, x4, y4);

    if (d1 != d2 && d3 != d4)
        return true;

    if (d1 == 0 && onSegment(x3, y3, x4, y4, x1, y1))
        return true;

    if (d2 == 0 && onSegment(x3, y3, x4, y4, x2, y2))
        return true;

    if (d3 == 0 && onSegment(x1, y1, x2, y2, x3, y3))
        return true;

    if (d4 == 0 && onSegment(x1, y1, x2, y2, x4, y4))
        return true;

    return false;
}


int main(){
    int n;

    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementación Intersección y proximidad aplicando geometría computacional.\n";

    cin >> n;

    vector< vector<int> > coordinates(n, vector<int>(8, 0));
    vector<bool> results;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 8; j++){
            cin >> coordinates[i][j];
        }
    }


    for(int i = 0; i < n; i++)
        results.push_back(segmentIntersection(coordinates[i][0], coordinates[i][1], coordinates[i][2], coordinates[i][3], coordinates[i][4], coordinates[i][5], coordinates[i][6], coordinates[i][7]));
    
    for(int i = 0; i < n; i++)
        cout << results[i] <<  "\n";
    
    return 0;
}

