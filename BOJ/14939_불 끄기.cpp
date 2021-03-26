#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
char bulb[11][11], com[11][11];
int ans = 101;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
void push(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > 10 || ny < 1 || ny > 10) continue;
		if (com[nx][ny] == 'O') com[nx][ny] = '#';
		else com[nx][ny] = 'O';
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			cin >> bulb[i][j];
	for (int key = 0; key < 1024; key++) { // 첫 줄에 대해서 누를지 말지 비트마스킹

		int cnt = 0;

		for (int i = 1; i <= 10; i++) // 비교 배열 저장
			for (int j = 1; j <= 10; j++)
				com[i][j] = bulb[i][j];

		for (int i = 1; i <= 10; i++) // key값으로 첫 줄 누르기
			if (key & (1 << (i - 1))) {
				cnt++;
				push(1, i);
			}

		for (int i = 2; i <= 10; i++) { // 2~10줄 누르기
			for (int j = 1; j <= 10; j++) {
				if (com[i - 1][j] == 'O') {
					push(i, j);
					cnt++;
				}
			}
		}

		bool possible = true;

		for (int i = 1; i <= 10; i++) // 가능한지 불가능한지 판단
			if (com[10][i] == 'O')
				possible = false;

		if (possible) ans = min(ans, cnt);
	}
	if (ans == 101) cout << -1;
	else cout << ans;
	return 0;
}