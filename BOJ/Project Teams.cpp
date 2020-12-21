#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int n,arr[10001],ans=200000;
int main() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++) cin >> arr[i];
	sort(arr, arr + 2 * n);
	for (int i = 0; i < n; i++) ans = min(ans, arr[i] + arr[2*n-1-i]);
	cout << ans;
	return 0;
}