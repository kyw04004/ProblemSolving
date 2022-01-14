#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int n, m, sum[100005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n  >> m;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		sum[i] = sum[i - 1] + num;
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}
	return 0;
}