#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
int n, h, chk[500005];
vector<int> bottom;
vector<int> top;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int len; cin >> len;
		if (i % 2 == 0) bottom.push_back(len);
		else top.push_back(len);
	}
	sort(bottom.begin(), bottom.end());
	sort(top.begin(),top.end());
	for (int i = 1; i <= h; i++) {
		int bottomCnt = 0, topCnt = 0;;
		int left = 0, right = bottom.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (i <= bottom[mid]) right = mid - 1, bottomCnt = bottom.size() - mid;
			else left = mid + 1;
		}
		int j = h - i;
		left = 0, right = top.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (j < top[mid]) right = mid - 1, topCnt = top.size() - mid;
			else left = mid + 1;
		}
		chk[i] = bottomCnt + topCnt;
	}
	sort(chk + 1, chk + h + 1);
	int ans = chk[1], ansCnt=0;
	for (int i = 1; i <= h; i++)
		if (chk[i] == ans) ansCnt++;
	cout << ans << ' ' << ansCnt;
	return 0;
}