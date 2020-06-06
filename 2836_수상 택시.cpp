#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
priority_queue<P, vector<P>, greater<P>> pq;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) pq.push({ -a,-b });
	}
	int right = pq.top().second;
	ll sum = (ll)abs(pq.top().first - pq.top().second);
	pq.pop();
	while (!pq.empty())
	{
		if (right <= pq.top().first)
		{
			sum += (ll)abs(pq.top().first - pq.top().second);
			right = pq.top().second;
		}
		else if (right <= pq.top().second)
		{
			sum += (ll)abs(pq.top().second - right);
			right = pq.top().second;
		}
		pq.pop();
	}
	printf("%lld", (ll)2 * sum + m);
	return 0;
}