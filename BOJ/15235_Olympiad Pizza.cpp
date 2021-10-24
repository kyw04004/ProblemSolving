#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, ans[1001];
queue<pair<int, int>> q;
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int need; cin >> need;
		q.push({ i,need });
	}
	int time = 0;
	while (!q.empty()) {
		time++;
		int num = q.front().first;
		int need = q.front().second;
		need--;
		q.pop();
		if (need == 0) ans[num] = time;
		else q.push({ num,need });
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i] << ' ';
	return 0;
}