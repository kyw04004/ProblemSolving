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
int n, m;
void go(vector<int> v, int index) {
	if (v.size() == m) {
		for (int i = 0; i < m; i++) cout << v[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = index; i <= n; i++) {
		if(v.size() > 0)
			if (i < v.back()) continue;
		v.push_back(i);
		go(v, index);
		v.pop_back();
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	vector<int> V;
	go(V, 1);
	return 0;
}