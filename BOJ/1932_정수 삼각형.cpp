#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int n, tri[505][505];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> tri[i][j];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, tri[n][i]);
	cout << ans;
	return 0;
}