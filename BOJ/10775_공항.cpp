#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int gate[100005], G, P, ans;
int find(int x) {
	if (gate[x] == x) return x;
	return gate[x] = find(gate[x]);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> G >> P;
	for (int i = 1; i <= G; i++) gate[i] = i;
	for (int i = 0; i < P; i++) {
		int gi; cin >> gi;
		int pi = find(gi);
		if (pi == 0) break;
		ans++;
		gate[pi] = pi - 1;
	}
	cout << ans;
	return 0;
}

