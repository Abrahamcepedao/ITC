#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long sum(vector<int> nums){
    long tot = 0;
    for(int i = 0; i < nums.size(); i++) tot += nums[i];
    return tot;
}


void calculate(vector<int> damage, string str, long k){
    long total = 0;
    long cons = 1; //consecutive
    char c = str[0]; //current char
    vector<int> nums;
    nums.push_back(damage[0]);
    for(int i = 1; i < str.length(); i++){
        if(c == str[i]){
            //is consecutive
            nums.push_back(damage[i]);
            cons++;

            if(i == str.size()-1){
                if (cons > k){

                    long dif = cons - k;
                    // delete numbers from nums
                    sort(nums.begin(), nums.end(), greater<int>());
                    for (int i = 0; i < dif; i++) nums.pop_back();
                    
                }
                total += sum(nums);
                nums.clear();
            }
        } else {
            //check if consecutives is greater than k
            if(cons > k) {
                
                long dif = cons - k;
                //delete numbers from nums
                sort(nums.begin(), nums.end(), greater<int>());
                for(int i = 0; i < dif; i++) nums.pop_back();
            } 
            cons = 1;
            total += sum(nums);
            nums.clear();
            nums.push_back(damage[i]);

            if(i == str.size()-1) total += damage[i];
            
            
            c = str[i];
            
        }
        

    }

    cout << total << endl;

}

int main() {
    long n, k;
    cin >> n;
    cin >> k;
    
    string str;

    vector< int > damage(n, 0);

    for (int i = 0; i < n; i++){
        cin >> damage[i];
    }

    cin >> str;

    calculate(damage, str, k);


    return 0;
}