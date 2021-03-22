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
int n, cnt, words[27];
void dfs(int index, int sum) {
	if (index == n) {
		if (sum == ((1 << 26) - 1)) cnt++;
		return;
	}
	dfs(index + 1, sum | words[index + 1]);
	dfs(index + 1, sum);
	return;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			words[i] |= (1 << (str[j] - 'a'));
	}
	dfs(0, 0);
	cout << cnt;
	return 0;
}