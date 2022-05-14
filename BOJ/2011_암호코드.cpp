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
string str;
int dp[5005];
int go(int idx) {
    if (idx == str.size()) return 1;
    int& ret = dp[idx];
    if (ret != -1) return ret;
    ret = 0;
    if (str[idx]  == '1') {
        if (idx + 2 < str.size() && str[idx+2] == '0') ret += go(idx + 1) % 1000000;
        else if (idx + 1 < str.size()) {
            if (str[idx + 1] != '0') {
                ret += go(idx + 1) % 1000000;
                ret += go(idx + 2) % 1000000;
            }
            else ret += go(idx + 2) % 1000000;
        }
        else ret += go(idx + 1) % 1000000;
    }
    else if (str[idx]  == '2') {
        if (idx + 2 < str.size() && str[idx + 2] == '0') ret += go(idx + 1) % 1000000;
        else if (idx + 1 < str.size()) {
            if(str[idx + 1] == '0') ret += go(idx + 2) % 1000000;
            else if (str[idx + 1] - '0' <= 6) {
                ret += go(idx + 2) % 1000000;
                ret += go(idx + 1) % 1000000;
            }
            else ret += go(idx + 1) % 1000000;
        }
        else ret += go(idx + 1) % 1000000;
    }
    else  ret += go(idx + 1) % 1000000;
    return ret % 1000000;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> str;
    bool correct = true;
    if (str[0] == '0') correct = false;
    for (int i = 0; i < str.size() - 1; i++) {
        if (2 < str[i] - '0' && str[i + 1] == '0') correct = false;
        if (str[i] == '0' && str[i + 1] == '0') correct = false;
    }
    if (!correct) cout << 0;
    else cout << go(0);
    return 0;
}