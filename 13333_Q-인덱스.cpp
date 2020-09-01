#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n, arr[1005];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int ans = n; ans >= 0; ans--) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (arr[i] >= ans) cnt++;
		if (cnt >= ans) {
			cout << ans;
			break;
		}
	}
	return 0;
}



