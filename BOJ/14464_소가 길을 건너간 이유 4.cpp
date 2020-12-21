#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
int cown, chickenn, chicken[20001],cnt,idx;
pair<pair<int, int>, int> cow[20001];
int main() {
	cin >> chickenn >> cown;
	for (int i = 0; i < chickenn; i++)
		scanf("%d", &chicken[i]);
	for (int i = 0; i < cown; i++) 
		scanf("%d %d", &cow[i].first.second, &cow[i].first.first);
	sort(chicken, chicken + chickenn);
	sort(cow, cow + cown);
	for (int i = 0; i < chickenn; i++) 
		for (int j = 0; j < cown; j++) 
			if (!cow[j].second&&cow[j].first.second <= chicken[i] && chicken[i] <= cow[j].first.first)
				cnt++, cow[j].second = 1,j=cown;
	cout << cnt;
	return 0;
}