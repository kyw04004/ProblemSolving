#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
int N, K, H, T, chk[3005][3005];
priority_queue<pp, vector<pp>, greater<pp>> pq;
int bfs(int H, int T) {
	chk[H][T] = 1;
	pq.push({ 0, {H,T} });
	while (!pq.empty()) {
		int H = pq.top().second.first;
		int T = pq.top().second.second;
		int cnt = pq.top().first;
		if (H == 0) return cnt;
		pq.pop();
		for (int i = 0; i <= K; i++) {
			int nH = H - i + (K - i);
			int nT = T + i - (K - i);
			if (H < i || T < (K - i) || nH < 0 || nT < 0) continue;
			if (!chk[nH][nT]) {
				chk[nH][nT] = 1;
				pq.push({ cnt + 1,{nH, nT} });
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		char state; cin >> state;
		if (state == 'H') H++;
		else T++;
	}
	cout << bfs(H, T);
	return 0;
}