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
int n, arr[22][22], ans=1e9, chk[22];
vector<pair<int, int>> zero;
void go(vector<int> v, int now) {
	if (v.size() == (n / 2)) {
		int com1 = 0;
		int com2 = 0;
		for (int i = 0; i < v.size() - 1; i++)
			for (int j = i + 1; j < v.size(); j++)
				com1 += (arr[v[i]][v[j]] + arr[v[j]][v[i]]);
		for (int i = 1; i <= n - 1; i++)
			for (int j = i + 1; j <= n; j++)
				if(chk[i] + chk[j] == 0)
					com2 += (arr[i][j] + arr[j][i]);
		ans = min(ans, abs(com1 - com2));
		return;
	}
	for (int i = now + 1; i <= n; i++) {
		chk[i] = 1;
		v.push_back(i);
		go(v, i);
		chk[i] = 0;
		v.pop_back();
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	vector<int> V;
	go(V, 0);
	cout << ans;
	return 0;
}