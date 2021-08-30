#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
typedef unsigned long long ll;
ll N, X, cnt, ans;
vector<ll> bottle;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> X;
	X *= 2;
	for (int i = 0; i < N; i++) {
		ll val; cin >> val;
		val *= 2;
		if (val == X) {
			ans++;
			continue;
		}
		bottle.push_back(val);
	}
	if(bottle.size())
		sort(bottle.begin(), bottle.end());
	int st = 0, en = bottle.size() - 1;
	while (st < en) {
		if (bottle[st] + bottle[en] >= (X / 2)) {
			cnt++;
			en--;
		}
		st++;
	}
	ans += cnt + (bottle.size() - (2 * cnt)) / 3;
	cout << ans;
	return 0;
}

