#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n, arr[3], ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d/%d", &a, &b);
		if (a == 1 && b == 4) arr[0]++;
		if (a == 1 && b == 2) arr[1]++;
		if (a == 3 && b == 4) arr[2]++;
	}
	ans = arr[2];
	if (arr[0] >= arr[2]) arr[0] -= arr[2];
	else arr[0] = 0;
	ans += (arr[1] / 2);
	if (arr[1] % 2 == 1) {
		ans++;
		if (arr[0] >= 2) arr[0] -= 2;
		else arr[0] = 0;
	}
	while (arr[0] > 0) {
		ans++;
		arr[0] -= 4;
	}
	cout << ans << "\n";
	return 0;
}