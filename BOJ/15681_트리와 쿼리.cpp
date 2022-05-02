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
int N, R, Q, dep[100001], dp[100001];
vector<vector<int>> tree;
void chkDepth(int now, int depth) {
    dep[now] = depth;
    for (int next : tree[now])
        if (!dep[next]) chkDepth(next, depth + 1);
}
int subNode(int root) {
    int& ret = dp[root];
    if (ret != -1) return ret;
    ret = 1;
    for (int next : tree[root])
        if (dep[next] > dep[root])
            ret += subNode(next);
    return ret;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> N >> R >> Q;
    tree.resize(N + 1);
    for (int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    chkDepth(R, 1);
    for (int i = 0; i < Q; i++) {
        int root; cin >> root;
        cout << subNode(root) << '\n';
    }
    return 0;
}