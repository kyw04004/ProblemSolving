#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int N, K, up[9], chk[9], ans;
void go(int sum, int day) {
    if (sum < 0) return;
    if (day == N) {
        ans++;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!chk[i]) {
            chk[i] = 1;
            go(sum + up[i] - K, day + 1);
            chk[i] = 0;
        }
    }
}
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> up[i];
    go(0, 0);
    cout << ans;
    return 0;
}