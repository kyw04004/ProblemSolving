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
int N, M, dp[41], ans = 1;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    int beforeNum = 0;
    for (int i = 0; i < M; i++) {
        int fixedNum; cin >> fixedNum;
        ans *= dp[fixedNum - 1 - beforeNum];
        beforeNum = fixedNum;
    }
    ans *= dp[N - beforeNum];
    cout << ans;
    return 0;
}