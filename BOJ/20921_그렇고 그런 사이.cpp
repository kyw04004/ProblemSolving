#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
int N, K, chk[4243];
vector<int> ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	if (N * (N - 1) / 2 == K) {
		for (int i = N; i >= 1; i--)
			cout << i << ' ';
		return 0;
	}
	int com = N - 1;
	while (K >= com) {
		ans.push_back(com + 1);
		chk[com + 1] = 1;
		K -= com;
		com--;
	}
	if (K > 0) {
		ans.push_back(K + 1);
		chk[K + 1] = 1;
	}
	for (int i = 1; i <= N; i++)
		if (chk[i] == 0) ans.push_back(i);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}