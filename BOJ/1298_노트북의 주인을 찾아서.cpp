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
int N, M, match, A[105], B[105], chk[105];
vector<int> v[105];
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
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= N; i++) {
		if (A[i] == -1) {
			memset(chk, 0, sizeof(chk));
			if (dfs(i)) match++;
		}
	}
	cout << match;
	return 0;
}