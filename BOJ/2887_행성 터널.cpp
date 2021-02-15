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
priority_queue<pair<ll,pair<ll,ll>>,
vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
ll n, parent[100005], sum;
struct planet {
	int x;
	int y;
	int z;
	int index;
}pla[100005];
bool xcompare(planet a, planet b) {
	return a.x < b.x;
}
bool ycompare(planet a, planet b) {
	return a.y < b.y;
}
bool zcompare(planet a, planet b) {
	return a.z < b.z;
}
ll find(ll x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(ll x, ll y, ll val) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	else {
		parent[y] = x;
		sum += val;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	for (ll i = 1; i <= n; i++) {
		parent[i] = i;
		pla[i].index = i;
		cin >> pla[i].x >> pla[i].y >> pla[i].z;
	}
	sort(pla+1,pla+n+1,xcompare);
	for (ll i = 1; i <= n - 1; i++)
		pq.push({ abs(pla[i].x - pla[i+1].x),{pla[i].index, pla[i+1].index} });
	sort(pla + 1, pla + n + 1, ycompare);
	for (ll i = 1; i <= n - 1; i++)
		pq.push({ abs(pla[i].y - pla[i + 1].y),{pla[i].index, pla[i + 1].index} });
	sort(pla + 1, pla + n + 1, zcompare);
	for (ll i = 1; i <= n - 1; i++)
		pq.push({ abs(pla[i].z - pla[i + 1].z),{pla[i].index, pla[i + 1].index} });
	while (!pq.empty()) {
		merge(pq.top().second.first, pq.top().second.second,
			pq.top().first);
		pq.pop();
	}
	cout << sum;
	return 0;
}