#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
int N, S, T, dp[10005][3];
string str1, str2, com;
int go(int index, int cnt) {
	if ((index + cnt)  == str2.size()) return 0;
	int &ret = dp[index + cnt][cnt];
	if (ret != -1) return ret;
	ret = 0;
	if (cnt < 2 && com[cnt] == str2[index + cnt])
		ret = max(ret, go(index, cnt + 1) + 1);
	if(index < str1.size() && str1[index] == str2[index+cnt])
		ret = max(ret, go(index + 1, cnt) + 1);
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cin >> str1 >> str2;
	cin >> S >> T;
	com = str1.substr(S, 1) + str1.substr(T, 1);
	str1.erase(S, 1);
	str1.erase(T - 1, 1);
	if (go(0, 0) == str2.size()) cout << "YES";
	else cout << "NO";
	return 0;
}