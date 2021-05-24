#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int N, input[1005], C;
map<int, pair<int, int>> m;
map<int, int> chk;
vector<pair<pair<int, int>, int>> sortedV;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> C;
	int cnt = N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		if (m[input[i]].first == 0) m[input[i]].second = cnt--;
		m[input[i]].first++;
	}

	for (int i = 0; i < N; i++)
		if (chk[input[i]] == 0) {
			chk[input[i]] = 1;
			sortedV.push_back({ m[input[i]], input[i] });
		}

	sort(sortedV.begin(), sortedV.end());

	for (int i = sortedV.size() - 1; i >= 0; i--)
		for (int j = 0; j < sortedV[i].first.first; j++)
			cout << sortedV[i].second << ' ';

	return 0;
}