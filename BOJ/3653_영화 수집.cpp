#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int t, n, m, h, height[100005];
vector<int> seg;
void update(int idx, int val) {
    idx += h - 1;
    seg[idx] = val;
    while (idx /= 2)
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}
int query(int now, int start, int end, int left, int right) { 
    if (end < left || right < start) return 0; 
    if (left <= start && end <= right) return seg[now]; 
    int mid = (start + end) / 2; 
    return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        memset(height, 0, sizeof(height));
        cin >> n >> m;
        h = 1;
        while (h < n + m) h *= 2;
        seg.clear();
        seg.resize(h * 2, 0);
        for (int i = 1; i <= n; i++) {
            height[i] = m + i;
            update(m + i, 1);
        }
        for (int i = 1; i <= m; i++) {
            int num; cin >> num;
            int pos = height[num];
            int ans = query(1, 1, h, 1, pos - 1);
            cout << ans << ' ';
            height[num] = m - i + 1;
            update(pos, 0);
            update(m - i + 1, 1);
        }
        cout << '\n';
    }
    return 0;
}
