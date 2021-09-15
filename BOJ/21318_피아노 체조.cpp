#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<stdio.h>
using namespace std;
typedef long long ll;
int N, paper[100005], sum[100005], Q;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> paper[i];
    for (int i = 1; i < N; i++) {
        int val = 0;
        if (paper[i] > paper[i + 1]) val = 1;
        sum[i] = sum[i - 1] + val;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        if (a == b) cout << "0\n";
        else cout << sum[b - 1] - sum[a - 1] << '\n';
    }
    return 0;
}