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
int N, cnt, h[1000005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int val; cin >> val;
		if (h[val + 1] == 0) cnt++, h[val]++;
		else h[val + 1]--, h[val]++;
	}
	cout << cnt;
	return 0;
}

