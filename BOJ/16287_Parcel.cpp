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
int w, n, arr[5001];
vector<pair<int, int>> val[400001];
int main() {
	cin >> w >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			val[arr[i] + arr[j]].push_back({ i,j });
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			int now = w - arr[i] - arr[j];
			if (now >= 0 && now<=400000 && val[now].size() >= 1) {
				for (int k = 0; k < val[now].size(); k++)
				{
					if (val[now][k].first == i) continue;
					if (val[now][k].first == j) continue;
					if (val[now][k].second == i) continue;
					if (val[now][k].second == j) continue;
					cout << "YES\n";
					return 0;
				}
			}
		}
	cout << "NO\n";
	return 0;
}