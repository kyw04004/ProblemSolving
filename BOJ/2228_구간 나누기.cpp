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
int dp[101][51][2];
int N, M, arr[101];
int go(int idx, int group, bool eat) {
    if (group > M) return -1e8;
    if (idx > N) {
        if (group == M) return 0;
        else return -1e8;
    }
    int& ret = dp[idx][group][eat];
    if (ret != -1e9) return ret;
    if (eat == false) {
        //æ»∏‘±‚
        ret = max(ret, go(idx + 1, group, false));
        //∏‘±‚ Ω√¿€
        ret = max(ret, go(idx + 1, group + 1, true) + arr[idx]);
        //∏‘∞Ì ¡æ∑·
        ret = max(ret, go(idx + 2, group + 1, false) + arr[idx]);
    }
    else {
        //∏‘±‚
        ret = max(ret, go(idx + 1, group, true) + arr[idx]);
        //∏‘∞Ì ¡æ∑·
        ret = max(ret, go(idx + 2, group, false) + arr[idx]);
    }
    return ret;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 51; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = -1e9;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cout << go(1, 0, 0);
    return 0;
}