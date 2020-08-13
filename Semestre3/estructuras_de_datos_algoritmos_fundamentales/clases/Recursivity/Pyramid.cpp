#include <iostream>
using namespace std;

void pyramid(int n, int m){
    for(int i = 1; i < n; i++){
        cout << " ";
    }
    for(int i = 0; i < m; i++){
        if(i % 2 == 0){
            cout << "*";
        } else{
            cout << " ";
        }
    }
    cout << "\n";
    if(n > 1){
        pyramid(n-1, m+2);
    }
}

int main(){
    int n; 
    cout << "Enter a number: ";
    cin >> n;
    pyramid(n,1);
    return 0;
}
