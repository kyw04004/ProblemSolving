#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
ll n, m;
p dot[100005];
vector<p> v;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) v.push_back({-a, -b});
	}
	if (v.size() == 0) cout << m;
	else {
		sort(v.begin(), v.end());
		ll sum = 0;
		ll left = v[0].first, right = v[0].second;
		for (int i = 1; i < v.size(); i++) {
			if (right < v[i].first) {
				sum += (right - left);
				left = v[i].first;
				right = v[i].second;
			}
			else right = max(right, v[i].second);
		}
		sum += (right - left);
		cout << 2 * sum + m;
	}
	return 0;
}