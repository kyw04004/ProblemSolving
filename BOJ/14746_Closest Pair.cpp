#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int n, m, one, two, Min = 1e9, cnt,chk;
int N[500001], M[500001];
int main() {
	cin >> n >> m;
	cin >> one >> two;
	for (int i = 0; i < n; i++) cin >> N[i];
	for (int i = 0; i < m; i++) cin >> M[i];
	sort(N, N + n);
	sort(M, M + m);
	int index = 1;
	for (int i = 0; i < n; i++) {
		for (int j = index; j < m; j++) {
			int bef = abs(N[i] - M[j - 1]);
			int now = abs(N[i] - M[j]);
			if (bef == Min) cnt++;
			if (bef < Min) Min = bef, cnt = 1;
			if (bef < now) {
				index = j;
				break;
			}
			if (j == m - 1) index = m;
		}
		if (index == m) {
			if (abs(N[i] - M[index-1]) == Min) cnt++;
			if (abs(N[i] - M[index-1]) < Min) Min = abs(N[i] - M[index-1]), cnt = 1;
		}
	}
	cout << Min + abs(one - two) << " " << cnt;
	return 0;
}