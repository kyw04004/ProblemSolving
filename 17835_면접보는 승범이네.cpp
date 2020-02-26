#include<stdio.h> 
#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> P;
ll n, m, k, a, b,c,Max,Maxi;
ll dist[100001];
vector<vector<P>> v(100001);
priority_queue<P, vector<P>, greater<P>> pq;
void dijk() {
	while (!pq.empty()) {
		ll cost = pq.top().first;
		ll here = pq.top().second;
		pq.pop();
		if (cost > dist[here]) continue;
		for (ll i = 0; i < v[here].size(); i++) {
			ll next = v[here][i].first;
			ll nextcost = v[here][i].second;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
			}
		}
	}
}
int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	for (ll i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		v[b].push_back({ a, c });
	}
	for (ll i = 1; i <= n; i++)
		dist[i] = 1e18;
	for (ll i = 1; i <= k; i++)
	{
		ll st;
		scanf("%lld", &st);
		dist[st] = 0;
		pq.push({0,st});
	}
	dijk();
	for (ll i = 1; i <= n; i++)
	{
		if (Max < dist[i]&&dist[i]!=1e18)
		{
			Max = dist[i];
			Maxi = i;
		}
	}
	printf("%lld\n", Maxi);
	printf("%lld\n", Max);
	return 0;
}