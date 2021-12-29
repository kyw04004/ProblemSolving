#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int n, arr[100005], Max, dp[100005][2];
int main() {
    Max = -1e9;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = arr[i];
        dp[i][1] = dp[i - 1][1] + arr[i];
        dp[i][0] = max(dp[i][0], dp[i - 1][0] + arr[i]);
        if (i > 1) dp[i][1] = max(dp[i][1], dp[i - 1][0]);
        Max = max(Max, max(dp[i][0], dp[i][1]));
    }
    cout << Max;
    return 0;
}