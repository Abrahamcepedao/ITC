#include <iostream>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;

	if(n == 1 || n == k)
		cout << -1 << endl;
	else if(n - 1 == k){
		cout << 1;
		for(int i = 1; i < n; i++)
			cout << " " << i + 1;
	}
	else{
		long long arr[n],num = k + 3;
		for(int i = 1; i < k + 1; i++)
			arr[i] = i + 1;

		for(int i = k + 1; num <= n; i++){
			arr[i] = num;
			num++;
		}
		arr[n - 1] = 1;
		arr[0] = k + 2;
		cout << arr[0];
		for(int i = 1; i < n; i++)
			cout << " " << arr[i];
		cout << endl;
	}

}