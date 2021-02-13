#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
vector<int> v[10];
int dp[10][100005], D;
int go(int now, int time) {
	if (time == D) {
		if (now == 1) return 1;
		else return 0;
	}
	int&ret = dp[now][time];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		ret += go(next, time + 1);
		ret %= 1000000007;
	}
	return ret % 1000000007;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> D;
	v[1].push_back(2);
	v[2].push_back(1);
	v[1].push_back(3);
	v[3].push_back(1);
	v[2].push_back(3);
	v[3].push_back(2);
	v[2].push_back(4);
	v[4].push_back(2);
	v[3].push_back(4);
	v[4].push_back(3);
	v[3].push_back(5);
	v[5].push_back(3);
	v[4].push_back(5);
	v[5].push_back(4);
	v[4].push_back(6);
	v[6].push_back(4);
	v[5].push_back(6);
	v[6].push_back(5);
	v[5].push_back(8);
	v[8].push_back(5);
	v[7].push_back(8);
	v[8].push_back(7);
	v[7].push_back(6);
	v[6].push_back(7);
	cout << go(1, 0);
	return 0;
}