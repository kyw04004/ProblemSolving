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
string str1, str2, str3;
int t, dp[202][202];
int go(int index1, int index2, int index3) {
	int& ret = dp[index1][index2];
	if (index3 == str3.size()) return 0;
	if (ret != -1) return ret;
	ret = 0;
	if (str3[index3] == str2[index2])
		ret = max(ret, go(index1, index2 + 1, index3 + 1)+1);
	if (str3[index3] == str1[index1])
		ret = max(ret, go(index1+1, index2, index3 + 1)+1);
	return ret;
}
int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		memset(dp, -1, sizeof(dp));
		cin >> str1 >> str2 >> str3;
		go(0, 0, 0);
		if (go(0,0,0) == str3.size()) printf("Data set %d: yes\n", i);
		else printf("Data set %d: no\n", i);
	}
	return 0;
}