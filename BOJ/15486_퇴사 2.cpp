#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
int N, T[1500001], P[1500001], dp[1500001];
int go(int now) {
    if (now == N + 1) return 0;
    int& ret = dp[now];
    if (ret != -1) return ret;
    ret = 0;
    if (now + T[now] <= N + 1) ret = max(ret, go(now + T[now]) + P[now]);
    ret = max(ret, go(now + 1));
    return ret;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> T[i] >> P[i];
    cout << go(1);
}
