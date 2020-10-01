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
ll k, edge[2100000], sum, com = 1, len;
void go(ll node,ll depth) {
	if (depth == k) return;
	go(node * 2, depth+1);
	go(node * 2 + 1,depth+1);
	if (edge[node * 2] != edge[node * 2 + 1])
		sum += abs(edge[node * 2] - edge[node * 2 + 1]);
	edge[node] += max(edge[node * 2], edge[node * 2 + 1]);
}
int main() {
	cin >> k;
	for (ll i = 1; i <= k; i++) com*=2,len += com;
	for (ll i = 1; i <= len; i++) {
		ll val;
		cin >> val;
		edge[i + 1] = val;
		sum += val;
	}
	go(1,0);
	cout << sum;
	return 0;
}