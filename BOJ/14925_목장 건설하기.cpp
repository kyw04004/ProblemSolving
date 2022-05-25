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
int board[1001][1001], dp[1001][1001];
int M, N, Max;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++) {
            if (board[i][j]) continue;
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i-1][j-1]) + 1;
            Max = max(Max, dp[i][j]);
        }
    cout << Max;
    return 0;
}
