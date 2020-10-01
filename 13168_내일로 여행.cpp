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
ll n, m, k, ticket, sum1, sum2, dist[101], order[201];
map <string, ll> ntoi;
vector <pair<ll, ll>> ntom[101], tom[101];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll >>> pq;
string name;
void dijk(vector<pair<ll, ll>> v[]) {
	while (!pq.empty()) {
		ll cost = pq.top().first;
		ll here = pq.top().second;
		pq.pop();
		if (cost > dist[here]) continue;
		for (ll i = 0; i < v[here].size(); i++) {
			ll next = v[here][i].second;
			ll nextcost = v[here][i].first;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
			}
		}
	}
}
int main() {
	cin >> n >> ticket;
	ticket *= 2;
	for (ll i = 0; i < n; i++) {
		cin >> name; ntoi[name] = i;
	}
	cin >> m;
	for (ll i = 0; i < m; i++) {
		cin >> name; order[i] = ntoi[name];
	}
	cin >> k;
	for (ll i = 0; i < k; i++) {
		string tran, st, en;
		ll price;
		cin >> tran >> st >> en >> price;
		price *= 2;
		ntom[ntoi[st]].push_back({ price, ntoi[en] });
		ntom[ntoi[en]].push_back({ price, ntoi[st] });
		if (tran == "Mugunghwa" || tran == "ITX-Saemaeul" || tran == "ITX-Cheongchun") price = 0;
		if (tran == "S-Train" || tran == "V-Train") price /= 2;
		tom[ntoi[st]].push_back({ price, ntoi[en] });
		tom[ntoi[en]].push_back({ price, ntoi[st] });
	}
	for (ll i = 0; i < m - 1; i++) {
		for (ll j = 0; j < n; j++) dist[j] = 1e18;
		dist[order[i]] = 0;
		pq.push({ 0,order[i] });
		dijk(ntom);
		sum1 += dist[order[i + 1]];
	}
	for (ll i = 0; i < m - 1; i++) {
		for (ll j = 0; j < n; j++) dist[j] = 1e18;
		dist[order[i]] = 0;
		pq.push({ 0, order[i] });
		dijk(tom);
		sum2 += dist[order[i + 1]];
	}
	sum2 += ticket;
	if (sum1 > sum2) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}