#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
vector<vector<pair<ll,ll>>> v(10001);
priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
ll n, m, t, chk[10001], sum, add;
void dijk(ll st)
{
	pq.push({ 0,1 });
	while (!pq.empty())
	{
		ll cost = pq.top().first;
		ll here = pq.top().second;
		pq.pop();
		if (chk[here]==1) continue;
		chk[here] = 1;
		sum += cost;
		for (ll i = 0; i < v[here].size(); i++)
		{
			ll next = v[here][i].first;
			ll nextcost = v[here][i].second;
			if (chk[next]==0)
				pq.push({nextcost, next});
		}
	}
}
int main() {
	scanf("%lld %lld %lld", &n, &m, &t);
	for (ll i = 1; i <= m; i++)
	{
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dijk(1);
	for (ll i = 1; i <= n - 2; i++)
	{
		add += t;
		sum += add;
	}
	printf("%lld", sum);
	return 0;
}


