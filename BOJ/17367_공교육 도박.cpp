#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int N;
double dp[7][7][1005], ans;
double money(int a, int b, int c) {
	if (a == b && b == c) return double(10000 + a * 1000);
	if (a == b || a == c) return double(1000 + a * 100);
	if (b == c) return double(1000 + b * 100);
	return double(max(a, max(b, c)) * 100);
}
double dfs(int a, int b, int index) {
	if (index == 0) return 0.0;
	double &ret = dp[a][b][index];
	if (ret != -1.0) return ret;
	ret = 0.0;
	for (int i = 1; i <= 6; i++)
		ret += max(money(a,b,i), dfs(b,i,index-1));
	ret /= 6.0;
	return ret;
}
int main() {
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			for (int k = 0; k <= 1000; k++)
				dp[i][j][k] = -1.0;
	cin >> N;
	for (int a = 1; a <= 6; a++)
		for (int b = 1; b <= 6; b++)
			ans += dfs(a, b, N - 2);
	ans /= 36.0;
	cout << fixed;
	cout.precision(6);
	cout << ans;
	return 0;
}