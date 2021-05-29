#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int n;
P thief, police[500005], Max[4];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> police[i].first >> police[i].second;
	cin >> thief.first >> thief.second;

	Max[0] = { thief.first, 1e9 };
	Max[1] = { thief.first, -1e9 };
	Max[2] = { -1e9, thief.second };
	Max[3] = { 1e9, thief.second };

	ll pd, td;
	int run = 4;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			pd = abs(Max[i].first - police[j].first) + abs(Max[i].second - police[j].second);
			td = abs(Max[i].first - thief.first) + abs(Max[i].second - thief.second);
			if (td >= pd) {
				run--;
				break;
			}
		}
	}

	if (run) cout << "YES";
	else cout << "NO";

	return 0;
}