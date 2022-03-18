#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
#include<unordered_map>
using namespace std;
typedef long long ll;
int dp[2501];
string str;
bool palindrome(int s, int e) {
	bool can = true;
	for (int i = 0; i < (e - s + 1) / 2; i++)
		if (str[s + i] != str[e - i]) {
			can = false;
			break;
		}
	return can;
}
int go(int s) {
	if (s == str.size()) return 0;
	int& ret = dp[s];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = s; i < str.size(); i++)
		if (palindrome(s, i)) 
			ret = min(ret, go(i + 1) + 1);
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> str;
	cout << go(0);
	return 0;
}