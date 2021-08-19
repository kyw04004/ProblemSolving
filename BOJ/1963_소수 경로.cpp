#include <iostream>
#include <vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int T, prime[100000], chk[100000];
string A, B;
void findPrime() {
	for (int i = 2; i <= 9999; i++)
		prime[i] = 1;
	for (int i = 2; i * i <= 9999; i++)
		for (int j = i * i; j <= 9999; j += i)
			prime[j] = 0;
}
int bfs(string a, int c) {
	queue<pair<string, int>> q;
	q.push({ a,c });
	while (!q.empty()) {
		string num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == B) return cnt;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j ++) {
				if (i + j == 0) continue;
				string nnum = num;
				nnum[i] = j + '0';
				int n = stoi(nnum);
				if (chk[n] || !prime[n]) continue;
				chk[n] = 1;
				q.push({ nnum, cnt + 1 });
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	findPrime();
	cin >> T;
	while (T--) {
		memset(chk, 0, sizeof(chk));
		cin >> A >> B;
		int ans = bfs(A, 0);
		if (ans == -1) cout << "impossible\n";
		else cout << ans << '\n';
	}
	return 0;
}