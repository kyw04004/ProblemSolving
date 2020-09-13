#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, l, k;
		vector <pair<int, int>> location;
		vector <int> leftime, rightime;
		vector<pair<int, int>> time;
		scanf("%d %d %d", &n, &l, &k);
		for (int i = 1; i <= n; i++) {
			int lo, id;
			scanf("%d %d", &lo, &id);
			location.push_back({ lo, id });
			if (id > 0) rightime.push_back({ l - lo });
			else leftime.push_back({ lo });
		}
		sort(location.begin(), location.end());
		sort(leftime.begin(), leftime.end());
		sort(rightime.begin(), rightime.end());
		for (int i = 0; i < leftime.size(); i++) 
			time.push_back({ leftime[i], location[i].second });
		for (int i = 0; i < rightime.size(); i++) 
			time.push_back({ rightime[i],location[location.size()-1-i].second });

		sort(time.begin(), time.end());
		for (int i = 0; i < time.size(); i++) {
			printf("%d\n", time[k-1].second);
			break;
		}
	}
	return 0;
}