#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int n, parent[300001];
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}
bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n - 2; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 2; i <= n; i++)
		if (!isUnion(i - 1, i)) {
			cout << i - 1 << " " << i;
			break;
		}
	return 0;
}
