#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int r, c, k, arr[101][101], rowCnt = 3, colCnt = 3;
void rCalc() {
	int maxCol = 0;
	for (int i = 1; i <= rowCnt; i++) {
		vector<p> v;
		int cnt[101] = {0,};
		for (int j = 1; j <= colCnt; j++) cnt[arr[i][j]]++;
		for (int j = 1; j <= 100; j++)
			if (cnt[j] > 0) v.push_back({ cnt[j], j });
		sort(v.begin(), v.end());
		maxCol = max(maxCol,  2 * (int) v.size());
		for (int j = 1; j <= 100; j++) arr[i][j] = 0;
		for (int j = 1; j <= min(50, (int)v.size()); j++) {
			arr[i][2 * j - 1] = v[j - 1].second;
			arr[i][2 *j] = v[j - 1].first;
		}
	}
	colCnt = maxCol;
}
void cCalc() {
	int maxRow = 0;
	for (int i = 1; i <= colCnt; i++) {
		vector<p> v;
		int cnt[101] = {0,};
		for (int j = 1; j <= rowCnt; j++) cnt[arr[j][i]]++;
		for (int j = 1; j <= 100; j++)
			if (cnt[j] > 0) v.push_back({ cnt[j], j });
		sort(v.begin(), v.end());
		maxRow = max(maxRow, 2 * (int)v.size());
		for (int j = 1; j <= 100; j++) arr[j][i] = 0;
		for (int j = 1; j <= min(50, (int) v.size()); j++) {
			arr[2 * j - 1][i] = v[j-1].second;
			arr[2 * j][i] = v[j-1].first;
		}
	}
	rowCnt = maxRow;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> r >> c >> k;
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	for (int i = 0; i <= 100; i++) {
		if (arr[r][c] == k) {
			cout << i;
			return 0;
		}
		if (rowCnt >= colCnt) rCalc();
		else cCalc();
	}
	cout << -1;
	return 0;
}