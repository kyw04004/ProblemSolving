#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,arr[1001],sum,XOR;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		XOR ^= arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);
	if (XOR == 0) cout << sum - arr[0];
	else cout << 0;
	return 0;
}
