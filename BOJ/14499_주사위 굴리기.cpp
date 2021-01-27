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
int n, m, x, y, k,Map[21][21];
int Front, Back, Top, Down, Left,Right;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> Map[i][j];
	for (int i = 1; i <= k; i++) {
		int nx,ny,command; cin >> command;
		if (command == 1) {
			nx = x;
			ny = y+1;
			if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
			int temp = Top;
			Top = Left;
			Left = Down;
			Down = Right;
			Right = temp;
			cout << Top << '\n';
			x = nx, y = ny;
		}
		if (command == 2) {
			nx = x;
			ny = y - 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			int temp = Top;
			Top = Right;
			Right = Down;
			Down = Left;
			Left = temp;
			cout << Top << '\n';
			x = nx, y = ny;
		}
		if (command == 3) {
			nx = x-1;
			ny = y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			int temp = Front;
			Front = Down;
			Down = Back;
			Back = Top;
			Top = temp;
			cout << Top << '\n';
			x = nx, y = ny;
		}
		if (command == 4) {
			nx = x + 1;
			ny = y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			int temp = Front;
			Front = Top;
			Top = Back;
			Back = Down;
			Down = temp;
			cout << Top << '\n';
			x = nx, y = ny;
		}
		if (Map[nx][ny] == 0) Map[nx][ny] = Down;
		else {
			Down = Map[nx][ny];
			Map[nx][ny] = 0;
		}
	}
	return 0;
}