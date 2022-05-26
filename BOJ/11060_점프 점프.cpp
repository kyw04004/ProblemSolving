#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
#include<unordered_map>
using namespace std;
int N, board[1001], dp[1001];
int go(int idx) {
    if (idx >= N) return 0;
    int& ret = dp[idx];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int i = 1; i <= board[idx]; i++)
        ret = min(ret, go(idx+i)+1);
    return ret;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> board[i];
    int ans = go(1);
    if (ans == 1e9) ans = -1;
    cout << ans;
    return 0;
}
