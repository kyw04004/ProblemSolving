#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
int n, m,k,arr[20][20], val, ans, ci,cj, a,b;
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			val++, arr[i][j] = val;
			if (arr[i][j] == k) ci = i, cj = j;
		}
	if (k) {
		for (int i = 1; i <= m; i++) arr[1][i] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= m; j++)
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		a = arr[ci][cj];
		memset(arr, 0, sizeof(arr));
		for (int i = cj; i <= m; i++) arr[ci][i] = 1;
		for (int i = ci + 1; i <= n; i++)
			for (int j = cj; j <= m; j++)
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		b = arr[n][m];
		ans = a * b;
	}
	else {
		for (int i = 1; i <= m; i++) arr[1][i] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= m; j++)
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		ans = arr[n][m];
	}
	cout << ans;
	return 0;
}

