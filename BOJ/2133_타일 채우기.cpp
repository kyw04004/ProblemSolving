#include<iostream>
#include<map>
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
int N, dp[31];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    dp[0] = 1, dp[2] = 3;
    for (int i = 4; i <= N; i+=2) {
        dp[i] += 3 * dp[i-2];
        for (int j = 4; j <= i; j += 2)
            dp[i] += 2 * dp[i - j];
    }
    cout << dp[N];
    return 0;
}