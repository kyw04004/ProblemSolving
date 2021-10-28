#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, L, ans;
vector<int> loc;
bool can(int len, vector<int> loc, int m) {
	for (int i = 0; i < loc.size() - 1; i++)
		if (loc[i + 1] - loc[i] > len) 
			m -= ((loc[i + 1] - loc[i] - 1) / len);
	if (m >= 0) return true;
	else return false;
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> L;
	loc.push_back(0);
	loc.push_back(L);
	for (int i = 0; i < N; i++) {
		int l; cin >> l;
		loc.push_back(l);
	}
	sort(loc.begin(), loc.end());
	int left = 0; int right = L;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (mid == 0) mid = 1;
		if (ans == mid) break;
		if (can(mid, loc, M)) ans = mid, right = mid - 1;
		else left = mid + 1;
		if (mid == 1) break;
	}
	cout << ans;
	return 0;
}