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
int n, input[22][22], dp[22][1 << 20];
int go(int num, int key) {
	if (num == n+1) return 0;
	int &ret = dp[num][key];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 1; i <= n; i++)
		if ((key & (1 << (i-1))) == 0)
			ret = min(ret, go(num+1, key | (1<<(i-1))) + input[num][i]);
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> input[i][j];
	cout << go(1, 0);
	return 0;
}