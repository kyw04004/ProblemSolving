#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
char tmp;
int n, a, visited[11], Max = -1;
pair <int, char> mat[11][4][5][5];
pair <int, int> loc[4] = { {0,0},{0,1},{1,0},{1,1} };
struct mater {
	int index, turn, l;
};
int calMax(vector <mater> v) {
	int num[5][5] = { 0, };
	char col[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			col[i][j] = 'W';
	for (int k = 0; k < v.size(); k++) {
		int x = loc[v[k].l].first;
		int y = loc[v[k].l].second;
		for (int i = x; i < x + 4; i++) {
			for (int j = y; j < y + 4; j++) {
				num[i][j] += mat[v[k].index][v[k].turn][i-x][j-y].first;
				if (num[i][j] < 0) num[i][j] = 0;
				else if (num[i][j] > 9) num[i][j] = 9;
				if (mat[v[k].index][v[k].turn][i-x][j-y].second == 'W') continue;
				col[i][j] = mat[v[k].index][v[k].turn][i-x][j-y].second;
			}
		}
	}

	int r = 0, b = 0, g = 0, y = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (col[i][j] == 'R') r += num[i][j];
			if (col[i][j] == 'B') b += num[i][j];
			if (col[i][j] == 'G') g += num[i][j];
			if (col[i][j] == 'Y') y += num[i][j];
		}
	}
	return 7 * r + 5 * b + 3 * g + 2 * y;
}

void turnMat(int Index, int turn) { // 재료를 회전하는 함수
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) 
			mat[Index][turn + 1][i][j] = mat[Index][turn][j][3 - i];
}

void sel(vector <mater> v) { // 재료를 선택하는 함수
	if (v.size() == 3) {
		Max = max(Max, calMax(v));// 그 재료 순열을 가지고 가마에 조합하는 함수
		return;
	}
	for (int i = 0; i < n; i++) { // 재료를 선택
		if (!visited[i]) {
			visited[i] = true;
			for (int j = 0; j < 4; j++) { // 회전한 횟수
				for (int k = 0; k < 4; k++) { // 위치
					v.push_back({ i,j,k });
					sel(v);
					v.pop_back();
				}
			}
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++) 
				cin >> mat[i][0][j][k].first;

		for (int j = 0; j < 4; j++) 
			for (int k = 0; k < 4; k++) 
				cin >> mat[i][0][j][k].second;

	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++) 
			turnMat(i, j);

	vector <mater> v = {};
	sel(v);
	cout << Max;
	return 0;
}