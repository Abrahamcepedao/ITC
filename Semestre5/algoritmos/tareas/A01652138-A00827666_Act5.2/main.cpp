//Actividad 5.2 Implementación backtracking con Bitmask
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
using namespace std;
  
vector<int> capList[101]; //list de gorras que contiene las personas que la tienen

int dp[1025][101];
  
int allmask; // caso base

//function to validate given permutation
//input: solTemp, solTotal
//output: true if valid, false otherwise
//complexity: O(n^2)
bool validatePermutation(vector<int> solTemp, vector< vector<int> > &solTotal){
    int n = solTemp.size();
    //check if the permutation is valid
    for(int i=0;i<n;i++){
        if(solTemp[i] == -1)
            return false;
        for(int j=i+1;j<n;j++){
            if(solTemp[i] == solTemp[j])
                return false;
        }
    }
    //check if the permutation is already in the list
    if(solTotal.size() != 0){
        bool valid = true;
        bool flag = true;
        for(int i = 0; i < solTotal.size();i++){
            for(int j = 0; j < n; j++){
                if(solTotal[i][j] != solTemp[j])
                    break;
                if (j == n-1)
                    return false;
            }
        }
    }

    return true;
}

//function to generate all permutations given a starting point
//input: solTemp, solTotal
//output: none
//complexity: O(n!)
void checkValid(vector<int> solTemp, vector< vector<int> > &solTotal){
    //check if the current numbers are valid
    for (int k = 0; k < solTemp.size(); k++){
        for(int l = k+1; l < solTemp.size(); l++){
            if(solTemp[k] != -1 && solTemp[k] == solTemp[l]){
                return;
            }
        }
    }

    //get missing elements
    vector<int> missing;
    for (int k = 0; k < solTemp.size(); k++){
        if(solTemp[k] == -1){
            missing.push_back(k);
        }
    }

    vector< vector<int> > permutations;
    vector< vector<int> > validPermutations;
    for(int k = 0; k < missing.size(); k++){
        //get possible elements for missing element
        vector<int> possible;
        for(int l = 0; l < 101; l++){
            for(int m = 0; m < capList[l].size(); m++){
                if(capList[l][m] == missing[k]){
                    possible.push_back(l);
                }
            }
        }
        
        if (k == 0){
            //for first missing element, generate all permutations
            for(int l = 0; l < possible.size(); l++){
                vector<int> permutation;
                bool valid = true;
                for(int m = 0; m < solTemp.size(); m++){
                    if(solTemp[m] == -1 && m == missing[k]){
                        permutation.push_back(possible[l]);
                    } else {
                        permutation.push_back(solTemp[m]);
                        if(solTemp[m] == possible[l]){
                            valid = false;
                            break;
                        }
                    }
                }
                if(valid){
                    permutations.push_back(permutation);
                }
            }
        }
        else{
            //for other missing elements, generate valid permutations
            for(int l = 0; l < possible.size(); l++){
                for(int m = 0; m < permutations.size(); m++){
                    bool valid = true;
                    vector<int> permutationTemp;
                    for(int n = 0; n < solTemp.size(); n++){
                        if(permutations[m][n] == -1 && n == missing[k]){
                            permutationTemp.push_back(possible[l]);
                        } else {
                            permutationTemp.push_back(permutations[m][n]);
                            if(permutations[m][n] == possible[l]){
                                valid = false;
                                break;
                            }
                        }
                    }
                    if(valid)
                        validPermutations.push_back(permutationTemp);
                    
                }
            }
        }
        
        
    }

    //check if the permutations are valid
    if(missing.size() == 0){
        //only one missing element
        for(int i = 0; i < permutations.size(); i++){
            if(validatePermutation(permutations[i], solTotal)){
                solTotal.push_back(permutations[i]);
            }
        }
    } else {
        //multiple missing elements
        for(int i = 0; i < validPermutations.size(); i++){
            if(validatePermutation(validPermutations[i], solTotal)){
                solTotal.push_back(validPermutations[i]);
            }
        }
    }
}
  
//function to count ways to assign unique cap to each person
//input: mask, i solutions, n, solTemp, solTotal
//output: number of ways to assign unique cap to each person
//complexity: O(n!)
long long int countWaysUtil(int mask, int i,  vector< vector<int> > &solutions, int n, vector<int> &solTemp, int count){
    if (mask == allmask) return 1; // all persons are wearing a cap
    if (i > 100) return 0; // no more caps to process
    if (dp[mask][i] != -1) return dp[mask][i]; //return answer if already solved
    
    long long int ways = countWaysUtil(mask, i+1, solutions, n, solTemp, count); //get ways without this cap
  
    int size = capList[i].size(); //side of persons having cap with id i

    for (int j = 0; j < size; j++){
        if (mask & (1 << capList[i][j])) continue; //person capList[i][j] is wearing a cap
        else {
            //check for valid permutation
            solTemp[capList[i][j]] = i;
            count++;
            if(count == n-1){
                checkValid(solTemp, solutions);
                for (int k = 0; k < n; k++){
                    solTemp[k] = -1;
                }
                count = 0;
            }
            ways += countWaysUtil(mask | (1 << capList[i][j]), i + 1, solutions, n, solTemp, count); //get ways with this cap
            
        } 
        ways %= MOD; //modulo
    }
  
    return dp[mask][i] = ways; //return result
}



  
//function to read input file
//input: n (number of people)
//output: none
//complexity: O(n)
void readInput(int n){
    string temp, str;
    int x;
    getline(cin, str);  
    for (int i=0; i<n; i++){
        getline(cin, str);
        stringstream ss(str);
  
        // read number of caps for each person
        while (ss >> temp){
            stringstream s;
            s << temp;
            s >> x;
  
            capList[x].push_back(i); // add person to capList
        }
    }
    vector< vector<int> > sol; //final solution
    vector<int> solTemp(n, -1); //temp solution
    int count = 0;

    allmask = (1 << n) - 1; //set bits for all n persons as 1

    // Initialize all entries in dp as -1
    for (int i=0; i<1025; i++)
        for (int j=0; j<101; j++)
            dp[i][j] = -1;

    // Call recursive function count ways
    cout << "\n\n" << countWaysUtil(0, 1, sol, n, solTemp, count) << endl;

    // Print all solutions
    for(int l = 0; l < sol.size(); l++){
        cout << "(";
        for(int m = 0; m < sol[l].size(); m++){
            cout <<  sol[l][m] << (m == sol[l].size()-1 ? "" : ", ");
        }
        cout << ")" << endl;
    }


}
  
int main(){ 
    int n;   // number of persons
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementación backtracking con Bitmask.\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Ingrese el número n: ";
    cin >> n;
    readInput(n);
    return 0;
}