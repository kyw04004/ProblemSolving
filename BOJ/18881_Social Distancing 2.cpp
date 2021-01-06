#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
pair<int, int> cows[1005];
int Min = 1e5, ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		cows[i] = { a,b };
	}
	sort(cows, cows+n);
	for (int i = 0; i < n-1; i++)
		if (cows[i].second != cows[i + 1].second)
			Min = min(Min, cows[i + 1].first - cows[i].first);
	for (int i = 0; i < n;i++) {
		if (cows[i].second == 1) {
			ans++;
			for (int j = i+1; j < n; j++) {
				if (cows[j].second == 1 && cows[j].first - cows[i].first < Min)
					i = j;
				else break;
			}
		}
	}
	cout << ans;
	return 0;
}
