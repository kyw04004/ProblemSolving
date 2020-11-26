#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
int n, m, arr[51][51], Max, mx, my;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,-1,0 };
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char input;
			cin >> input;
			if (input == 'o') arr[i][j] = 1;
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int com = 0;
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (arr[i][j] || nx<1 || nx>n || ny<1 || ny>m) continue;
				if (arr[nx][ny]) com++;
			}
			if (Max < com) {
				Max = com;
				mx = i;
				my = j;
			}
		}
	}
	Max = 0;
	arr[mx][my] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int com = 0;
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (!arr[i][j] || nx<1 || nx>n || ny<1 || ny>m) continue;
				if (arr[nx][ny]) com++;
			}
			Max += com;
		}
	}
	cout << Max / 2;
	return 0;
}