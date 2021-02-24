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
int board[10][10], End;
vector<pair<int, int>> zero;
bool possible(int x, int y, int num) {
	for (int i = 0; i < 9; i++)
		if (board[x][i] == num) return false;
	for (int i = 0; i < 9; i++)
		if (board[i][y] == num) return false;
	for(int i= 3*(x/3) ; i <= 3 * (x / 3)+2;i++)
		for (int j = 3 * (y / 3); j <= 3 * (y / 3) + 2; j++)
			if (board[i][j] == num) return false;
	return true;
}
void go(int now) {
	if (now == zero.size()) {
		End = 1;
		return;
	}
	int x = zero[now].first;
	int y = zero[now].second;
	for (int i = 1; i <= 9; i++) {
		if (possible(x, y, i)) {
			board[x][y] = i;
			go(now + 1);
			if (End) return;
			board[x][y] = 0;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) zero.push_back({ i,j });
		}
	go(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}