#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
ll N, M, sum[1000005], mod[1005], cnt;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
		sum[i] %= M;
	}
	for (int i = 1; i <= N; i++) mod[sum[i]]++;
	cnt = mod[0];
	for (int i = 0; i < M; i++) {
		if (mod[i] <= 1) continue;
		cnt += mod[i] * (mod[i] - 1) / 2;
	}
	cout << cnt;
	return 0;
}

