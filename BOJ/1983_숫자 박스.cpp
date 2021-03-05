#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n, dp[405][405][405], ans, zero1, zero2;
vector <int> arr, brr;
int go(int now, int z1, int z2) {
	if (now == n) {
		if (z1 == zero1 && z2 == zero2) return 0;
		else return -1e9;
	}
	int &ret = dp[now][z1][z2];
	if (ret != -2e9) return ret;
	ret = -40000;
	int a = max( 0, now - z1);
	int b = max( 0, now - z2);
	if(now-z1 <= arr.size()-1 && now - z2 <= brr.size() - 1)
		ret = max(ret, go(now + 1, z1, z2) + (arr[a] * brr[b]) );
	if (z1 < zero1) ret = max(ret, go(now + 1, z1 + 1, z2));
	if (z2 < zero2) ret = max(ret, go(now + 1, z1, z2 + 1));
	if (z1 < zero1 && z2 < zero2) ret = max(ret, go(now + 1, z1 + 1, z2 + 1));
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= 400; i++)
		for (int j = 0; j <= 400; j++)
			for (int k = 0; k <= 400; k++)
				dp[i][j][k] = -2e9;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		if (val == 0) zero1++;
		else arr.push_back(val);
	}
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		if (val == 0) zero2++;
		else brr.push_back(val);
	}
	cout << go(0, 0, 0);
	return 0;
}