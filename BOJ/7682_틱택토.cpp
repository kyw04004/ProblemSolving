#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
char board[4][4];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		int xCnt = 0, oCnt = 0;
		string str;
		cin >> str;
		if (str == "end") break;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++) {
				board[i][j] = str[(i - 1) * 3 + j - 1];
				if (board[i][j] == 'O') oCnt++;
				if (board[i][j] == 'X') xCnt++;
			}
		int line = 0;
		map<char,int> c;
		for (int i = 1; i <= 3; i++)
			if (board[i][1] != '.' && board[i][1] == board[i][2] && board[i][2] == board[i][3])
				line++, c[board[i][1]] = 1;
		for (int i = 1; i <= 3; i++)
			if (board[1][i] != '.' && board[1][i] == board[2][i] && board[2][i] == board[3][i])
				line++, c[board[1][i]] = 1;
		if(board[1][1] != '.' && board[1][1] == board[2][2] && board[2][2] == board[3][3])
			line++, c[board[1][1]] = 1;
		if (board[1][3] != '.' && board[1][3] == board[2][2] && board[2][2] == board[3][1])
			line++, c[board[1][3]] = 1;
		if (line == 0) {
			if(xCnt == 5 && oCnt == 4) cout << "valid\n";
			else cout << "invalid\n";
		}
		else if (line == 1) {
			if (c['X']) {
				if(xCnt == oCnt+1) cout << "valid\n";
				else cout << "invalid\n";
			}
			else {
				if (xCnt == oCnt) cout << "valid\n";
				else cout << "invalid\n";
			}
		}
		else if (line == 2) {
			if (c['X'] && !c['O'] && xCnt == 5 && oCnt == 4) cout << "valid\n";
			else cout << "invalid\n";
		}
		else cout << "invalid\n";
	}
	return 0;
}