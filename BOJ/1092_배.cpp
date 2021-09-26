#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int N, M, ans;
int c[51], box[10005], chk[51];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> c[i];
	cin >> M;
	for (int i = 0; i < M; i++) cin >> box[i];
	sort(c, c + N);
	sort(box, box + M);
	int idx = 0;
	for (int i = 0; i < M; i++) {
		if (ans == -1) break;
		int w = box[i];
		while (w > c[idx]) {
			idx++;
			if (idx == N) {
				ans = -1;
				break;
			}
		}
		if (w <= c[idx]) {
			chk[idx]++;
			if (chk[idx] >= (chk[idx] + M - i - 2) / (N - idx) + 1) idx++;
		}
	}
	if (ans != -1) for (int i = 0; i < N; i++) ans = max(ans, chk[i]);
	cout << ans;
	return 0;
}

