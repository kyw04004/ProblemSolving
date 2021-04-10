#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int R, C, T, Map[51][51], Com[51][51], AirC1, AirC2;
int dx[4] = { 0, 0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void Spread() {
	memset(Com, 0, sizeof(Com));
	for (int i = 1; i <= R; i++) { // 미먼 확산
		for (int j = 1; j <= C; j++) {
			if (Map[i][j] == -1 || Map[i][j] == 0) continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (Map[nx][ny] == -1 || nx < 1 || nx > R || ny < 1 || ny > C) continue;
				Com[nx][ny] += (Map[i][j] / 5);
				cnt++;
			}
			Com[i][j] += Map[i][j] - cnt * (Map[i][j] / 5);
		}
	}
	
	Com[AirC1][1] = -1;
	Com[AirC2][1] = -1;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			Map[i][j] = Com[i][j];
}
void UpRota() {
	int temp1 = Map[1][1];
	int temp2 = Map[1][C];
	int temp3 = Map[AirC1][C];

	for (int j = C; j > 2; j--) // 아래쪽 순환
		Map[AirC1][j] = Map[AirC1][j-1];
	Map[AirC1][2] = 0;

	for (int i = 1; i < AirC1 - 1; i++) // 오른쪽 순환
		Map[i][C] = Map[i + 1][C];
	Map[AirC1 - 1][C] = temp3;

	for (int j = 1; j < C - 1; j++) // 위쪽 순환
		Map[1][j] = Map[1][j + 1];
	Map[1][C - 1] = temp2;

	for (int i = AirC1 - 1; i > 2; i--) // 왼쪽 순환
		Map[i][1] = Map[i - 1][1];
	Map[2][1] = temp1;
}
void DownRota() {
	int temp1 = Map[AirC2][C];
	int temp2 = Map[R][C];
	int temp3 = Map[R][1];
	for (int j = C; j > 2; j--) // 위쪽 순환
		Map[AirC2][j] = Map[AirC2][j - 1];
	Map[AirC2][2] = 0;

	for (int i = R; i > AirC2 + 1; i--) // 오른쪽 순환
		Map[i][C] = Map[i-1][C];
	Map[AirC2 + 1][C] = temp1;

	for (int j = 1; j < C - 1; j++) // 아래쪽 순환
		Map[R][j] = Map[R][j + 1];
	Map[R][C - 1] = temp2;

	for (int i = AirC2 + 1; i < R - 1; i++) //왼쪽 순환
		Map[i][1] = Map[i + 1][1];
	Map[R - 1][1] = temp3;
}
int Sum() {
	int sum = 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (Map[i][j] > 0) sum += Map[i][j];
	return sum;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			cin >> Map[i][j];
			if (AirC1 == 0 && Map[i][j] == -1)  AirC1 = i, AirC2 = i + 1;
		}
	for (int Second = 1; Second <= T; Second++) {
		Spread();
		UpRota();
		DownRota();
	}
	cout << Sum();
	return 0;
}