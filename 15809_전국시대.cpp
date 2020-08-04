#include<iostream>
#include<istream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int n, m,input[100001],parent[100001];
vector <int> ans;
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
	input[x] += input[y];
	input[y] = 0;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int s, a, b; cin >> s >> a >> b;
		if (s == 1) merge(a, b);
		if (s == 2) {
			int aa = find(a);
			int bb = find(b);
			int asum = input[aa], bsum = input[bb];
			if (asum > bsum) {
				input[aa] -= input[bb];
				input[bb] = 0;
				merge(a,bb);
			}
			else if (asum == bsum) input[aa] = 0, input[bb] = 0;
			else {
				input[bb] -= input[aa];
				input[aa] = 0;
				merge(b, aa);
			}
		}
	}
	sort(input + 1, input + n + 1);
	for (int i = 1; i <= n; i++)
		if (input[i]) ans.push_back(input[i]);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}
