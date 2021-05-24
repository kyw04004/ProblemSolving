#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int N, deskState[1005][1005];
pair<int, int> pro, sung;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> deskState[i][j];
			if (deskState[i][j] == 5) pro = { i, j };
			if (deskState[i][j] == 2) sung = { i, j };
		}
	int d = (pro.first - sung.first)*(pro.first - sung.first) + (pro.second - sung.second)*(pro.second - sung.second);
	if (d < 25) cout << 0;
	else {
		int cnt = 0;
		int x1 = min(pro.first, sung.first);
		int x2 = max(pro.first, sung.first);
		int y1 = min(pro.second, sung.second);
		int y2 = max(pro.second, sung.second);
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				if (deskState[i][j] == 1) cnt++;
		if (cnt >= 3) cout << 1;
		else cout << 0;
	}
	return 0;
}