#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int cnt = 0;
		int n, k, arr[1001] = { 0, };
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		sort(arr + 1, arr + 1 + n);
		int index = 2;
		while (index <= n) {
			if (arr[index] + arr[1] <= k)
				arr[index] += arr[1], cnt++;
			else index++;
		}
		cout << cnt << "\n";
	}
	return 0;
}