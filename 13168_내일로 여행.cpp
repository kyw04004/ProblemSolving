#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int n,m,k, ticket,sum1,sum2,dist[101],order[201];
map <string, int> ntoi;
vector <pair<int,int>> ntom[101],tom[101];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int >>> pq;
string name;
void dijk(vector<pair<int, int>> v[]) {
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (cost > dist[here]) continue;
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].second;
			int nextcost = v[here][i].first;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({dist[next],next });
			}
		}
	}
}
int main() {
	cin >> n >> ticket;
	for (int i = 0; i < n; i++) {
		cin >> name; ntoi[name] = i;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> name; order[i] = ntoi[name];
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		string tran, st, en;
		int price;
		cin >> tran >> st >> en >> price;
		ntom[ntoi[st]].push_back({price, ntoi[en]});
		ntom[ntoi[en]].push_back({price, ntoi[st]});
		if (tran == "Mugunghwa" || tran == "ITX-Saemaeul" || tran == "ITX-Cheongchun") price = 0;
		if (tran == "S-Train" || tran == "V-Train") price /=2;
		tom[ntoi[st]].push_back({ price, ntoi[en] });
		tom[ntoi[en]].push_back({ price, ntoi[st] });
	}
	for (int i = 0; i < m-1; i++) {
		for (int j = 0; j < n; j++) dist[j] = 1e9;
		dist[order[i]] = 0;
		pq.push({0,order[i]});
		dijk(ntom);
		sum1 += dist[order[i+1]];
	}
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++) dist[j] = 1e9;
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