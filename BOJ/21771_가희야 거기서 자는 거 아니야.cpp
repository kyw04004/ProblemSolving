#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
char board[101][101];
int R, C, gR, gC, pR, pC, pArea;
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	cin >> gR >> gC >> pR >> pC;
	for (int i = 1; i <= R; i++) 
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'P') pArea++;
		}
	if (pArea < pR * pC) cout << 1;
	else cout << 0;

	return 0;
}