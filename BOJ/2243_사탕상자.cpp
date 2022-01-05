#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
int n, h = 1;
vector<int> seg;
void update(int idx, int val) {
	idx += (h - 1);
	seg[idx] += val;
	while (idx/= 2) 
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}
int nquery(int now, int val) {
	if (now >= h) return now - h + 1;
	if (seg[now * 2] >= val) return nquery(now * 2, val);
	else return nquery(now * 2 + 1, val - seg[now * 2]);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	while (h < 1e6) h *= 2;
	seg.resize(h * 2);
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b;
		if (a == 1) {
			int num = nquery(1, b);
			cout << num << '\n';
			update(num, -1);
		}
		else {
			cin >> c;
			update(b, c);
		}
	}
	return 0;
}