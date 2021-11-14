//Actividad 4.2 Implementación Polígonos Convexos aplicando geometría computacional
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

struct Point{
    int x;
    int y;
};

Point p0;

//function to swap two elements in vector
//input: point1, point2
//output: none
//complexity: O(1)
void swapPoints(Point &p1, Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

//function to calculate the orientation
//input: point1, point2, point3
//output: 0 if colinear, 1 if clockwise, 2 if counterclockwise
//complexity: O(1)
int getOrientation(Point p, Point p1, Point p2) {
    int val = (p1.y - p.y) * (p2.x - p1.x) - (p1.x - p.x) * (p2.y - p1.x);
    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

//function to calculate distance between two points
//input: point1
//output: distance between two points
//complexity: O(1)
int getDistance(Point p){ return pow(p0.x - p.x, 2) + pow(p0.y - p.y, 2); };

//function to compare two points
//input: point1, point2
//output: true if point1 is closer to p0, false otherwise
//complexity: O(1)
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    int o = getOrientation(p0, *p1, *p2);
    if (o == 0) return getDistance(*p2) >= getDistance(*p1) ? -1 : 1;
    return (o == 2)? -1: 1;
}

//function to get next to top point in a stack
//input: stack
//output: next to top point in a stack
//complexity: O(1)
Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

//function to  find the convex hull of a set of points
//input: vector of points
//output: vector of points
//complexity: O(NlogN)
void findConvex(vector< Point > points, int n){
    //find bottommost point
    int bottommost = 0;
    for(int i = 1; i < n; i++){
        if(points[i].y < points[bottommost].y){
            bottommost = i;
        }
    }

    //swap bottommost point with point 0
    swapPoints(points[0], points[bottommost]);

    //sort points by polar angle with point 0
    qsort(&points[1], n-1, sizeof(Point), compare);
    
    //ommit points with same polar angle
    int count = 1;
    for(int i = 1; i < n; i++){
        while(i < n-1  && getOrientation(p0, points[i], points[i+1]) == 0) i++;
        points[count] = points[i];
        count++;
    }

    if (count < 3) return; // degenerate case

    stack<Point> st; //stack of points

    //push first three points
    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);

    //generate convex hull
    for(int i = 3; i < count; i++){
        while(st.size() > 1 && getOrientation(nextToTop(st), st.top(), points[i]) != 2) st.pop();
        st.push(points[i]);
    }

    cout << endl;

    //print convex hull
    cout << "Convex hull: \n";
    while(!st.empty()){
        Point p = st.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        st.pop();
    }
    cout << endl;

}


int main(){
    //read number of points
    int n, x, y;
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementación Polígonos Convexos aplicando geometría computacional.\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Ingrese el numero de puntos> ";
    cin >> n;

    //vector points
    vector<Point> points;

    for(int i = 0; i < n; i++){
        Point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    findConvex(points, n);
 
    return 0;
}
