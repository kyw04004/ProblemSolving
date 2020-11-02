#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
vector <vector<int>> v;
stack <int> ans;
int chk[32005];
void topology_sort(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!chk[next]) {
			chk[next] = 1;
			topology_sort(next);
		}
	}
	ans.push(node);
}
int main() {
	int n, k;
	cin >> n >> k;
	v.resize(n + 1);
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		if (!chk[i]) {
			chk[i] = 1;
			topology_sort(i);
		}
	while (!ans.empty()) {
		printf("%d ",ans.top());
		ans.pop();
	}
	return 0;
}