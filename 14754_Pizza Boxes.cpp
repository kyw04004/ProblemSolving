#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
ll n, m, arr[1001][1001], sum1, sum2, chk[1001][1001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			sum1 += arr[i][j];
		}
	for (int i = 1; i <= n; i++) {
		ll Max = -1;
		for (int j = 1; j <= m; j++)
			if (arr[i][j] > Max)
				Max = arr[i][j];
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == Max)
				chk[i][j] = 1;
	}
	for (int i = 1; i <= m; i++) {
		ll Max = -1;
		for (int j = 1; j <= n; j++)
			if (arr[j][i] > Max)
				Max = arr[j][i];
		for (int j = 1; j <= n; j++)
			if (arr[j][i] == Max)
				chk[j][i] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (chk[i][j] == 1) sum2 += arr[i][j];
	cout << sum1 - sum2;
	return 0;
}