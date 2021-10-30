#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, V;
int node[200005];
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> V;
	for (int i = 1; i <= N; i++) cin >> node[i];
	for (int i = 1; i <= M; i++) {
		int K; cin >> K;
		K += 1;
		if (K <= N) cout << node[K] << '\n';
		else {
			K -= V;
			K %= (N - V + 1);
			cout << node[K + V] << '\n';
		}
	}
	return 0;
}