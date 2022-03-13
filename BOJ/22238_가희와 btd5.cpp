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
#include<unordered_set>
using namespace std;
typedef long long ll;
vector<ll> target;
ll N, M, x, y, sum;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll hp;
		cin >> x >> y >> hp;
		target.push_back(hp);
	}
	ll m = gcd(abs(x), abs(y));
	x /= m, y /= m;
	sort(target.begin(), target.end());
	for (int i = 0; i < M; i++) {
		ll a, b, damage;
		cin >> a >> b >> damage;
		m = gcd(abs(a), abs(b));
		a /= m, b /= m;
		if (!(a == x && b == y)) {
			cout << N << '\n';
			continue;
		}
		sum += damage;
		int left = 0, right = target.size() - 1;
		int idx = -1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (target[mid] <= sum) {
				idx = mid;
				left = mid + 1;
			}
			else right = mid - 1;
		}
		if (idx != -1) N = (target.size() - idx - 1);
		cout << N << '\n';
	}
	return 0;
}