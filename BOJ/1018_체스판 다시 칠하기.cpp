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
int w, b, n, m, ans=2505;
char board[55][55];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	for (int I = 1; I <= n - 7; I++) {
		for (int J = 1; J <= m - 7; J++) {
			int paint = 0;
			for (int i = I; i <= I + 7; i++) {
				char com;
				if (i % 2 == 1) com = 'W';
				else com = 'B';
				for (int j = J; j <= J + 7; j++) {
					if (j % 2 == 1 && board[i][j] != com) paint++;
					if (j % 2 == 0 && board[i][j] == com) paint++;
				}
			}
			ans = min(ans, paint);
		}
	}
	for (int I = 1; I <= n - 7; I++) {
		for (int J = 1; J <= m - 7; J++) {
			int paint = 0;
			for (int i = I; i <= I + 7; i++) {
				char com;
				if (i % 2 == 1) com = 'B';
				else com = 'W';
				for (int j = J; j <= J + 7; j++) {
					if (j % 2 == 1 && board[i][j] != com) paint++;
					if (j % 2 == 0 && board[i][j] == com) paint++;
				}
			}
			ans = min(ans, paint);
		}
	}
	cout << ans;
	return 0;
}