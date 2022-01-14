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
int dp[100001][5][5];
vector<int> v;
int go(int idx,int left, int right) {
	if (idx == v.size()) return 0;
	int& ret = dp[idx][left][right];
	if (ret != -1) return ret;
	ret = 1e9;
	if(left == 0)  ret = min(ret, go(idx + 1, v[idx], right) + 2);
	if(right == 0)  ret = min(ret, go(idx + 1, left, v[idx]) + 2);
	else {
		//left go
		int dif = abs(v[idx] - left);
		if (dif == 0) ret = min(ret, go(idx + 1, v[idx], right) + 1);
		else if (dif % 2) ret = min(ret, go(idx + 1, v[idx], right) + 3);
		else ret = min(ret, go(idx + 1, v[idx], right) + 4);
		//right go
		dif = abs(v[idx] - right);
		if (dif == 0) ret = min(ret, go(idx + 1, left, v[idx]) + 1);
		else if (dif % 2) ret = min(ret, go(idx + 1, left, v[idx]) + 3);
		else ret = min(ret, go(idx + 1, left, v[idx]) + 4);
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		int val; cin >> val;
		if (val == 0) break;
		v.push_back(val);
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0, 0);
	return 0;
}