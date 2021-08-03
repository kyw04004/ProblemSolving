#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int V, E, schk[100005], scc[100005], S, cnt, tchk[100005];
vector<vector<int>> v, ans;
stack<int> st;
int dfs(int now) {
    st.push(now);
    schk[now] = S++;
    int parent = schk[now];
    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        if (schk[next] == -1) parent = min(parent, dfs(next));
        else if (scc[next] == -1) parent = min(parent, schk[next]);
    }
    if (parent == schk[now]) {
        vector<int> vscc;
        while (1) {
            int here = st.top();
            st.pop();
            scc[here] = cnt;
            vscc.push_back(here);
            if (here == now) break;
        }
        sort(vscc.begin(), vscc.end());
        ans.push_back(vscc);
        cnt++;
    }
    return parent;
}
void dfs2(int now) {
    tchk[now] = 1;
    for (int i = 0; i < v[now].size(); i++)
        if (!tchk[v[now][i]]) dfs2(v[now][i]);
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        memset(schk, -1, sizeof(schk));
        memset(scc, -1, sizeof(scc));
        memset(tchk, 0, sizeof(tchk));
        cnt = 0;
        cin >> V >> E;
        ans.clear();
        v.clear();
        v.resize(V + 1);
        for (int i = 0; i < E; i++) {
            int a, b; cin >> a >> b;
            v[a].push_back(b);
        }
        for (int i = 0; i < V; i++)
            if (schk[i] == -1) dfs(i);
        dfs2(ans[cnt - 1][0]);
        bool confused = false;
        for (int i = 0; i < V; i++)
            if (!tchk[i]) confused = true;
        if (confused) cout << "Confused\n";
        else
            for (int j = 0; j < ans[cnt - 1].size(); j++)
                cout << ans[cnt - 1][j] << '\n';
        cout << '\n';
    }
    return 0;
}