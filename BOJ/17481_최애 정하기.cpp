#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
map<string, int> m;
int N, M, match, A[1005], B[1005], chk[1005];
vector<int> v[1005];
bool dfs(int a) {
	chk[a] = 1;
	for (int i = 0; i < v[a].size(); i++) {
		int b = v[a][i];
		if (B[b] == -1 || !chk[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		string name; cin >> name;
		m[name] = i;
	}
	for (int i = 1; i <= N; i++) {
		int K; cin >> K;
		for (int j = 1; j <= K; j++) {
			string name; cin >> name;
			v[i].push_back(m[name]);
		}
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= N; i++) {
		if (A[i] == -1) {
			memset(chk, 0, sizeof(chk));
			if (dfs(i)) match++;
		}
	}
	if (match == N) cout << "YES";
	else cout << "NO\n" << match;
	return 0;
}