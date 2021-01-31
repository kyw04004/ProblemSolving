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
int n, m,ans=1e9;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<int> com;
void go(int depth) {
	if (com.size() == m) {
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int Min = 1e9;
			for (int j = 0; j < com.size(); j++) {
				Min = min(Min, abs(chicken[com[j]].first - home[i].first) + abs(chicken[com[j]].second - home[i].second));
			}
			sum += Min;
		}
		ans = min(ans, sum);
		return;
	}
	if (depth == chicken.size()) return;
	com.push_back(depth);
	go(depth + 1);
	com.pop_back();
	go(depth + 1);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			if (a == 1) home.push_back({ i,j });
			if (a == 2) chicken.push_back({ i,j });
		}
	go(0);
	cout << ans;
	return 0;
}