#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, arr[5001], cnt, dp[400001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for(int i=0;i<=400000;i++) dp[i] = 5005;
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n - 1; j++) {
			int val = 200000 + arr[i] + arr[j];
			dp[val] = min(j, dp[val]);
		}
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++) {
			int val = 200000 + arr[i] - arr[j];
			if (dp[val] != 5005 && dp[val] < i)
				cnt++, j=i;
		}
	cout << cnt;
	return 0;
}