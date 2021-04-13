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
int N, A[505][505], sum;
//¿Þ,¾Æ,¿À,À§
int dx[4][10] = { {-2,-1,-1,-1,0,1,1,1,2,0},
{-1,-1,0,0,0,0,1,1,2,1},
{-2,-1,-1,-1,0,1,1,1,2,0},
{-2,-1,-1,0,0,0,0,1,1,-1} };
int dy[4][10] = { {0,-1,0,1,-2,-1,0,1,0,-1},
{-1,1,-2,-1,1,2,-1,1,0,0},
{0,-1,0,1,2,-1,0,1,0,1},
{0,-1,1,-2,-1,1,2,-1,1,0} };
int ds[4][10] = { {2,10,7,1,5,10,7,1,2,-1},
{1,1,2,7,7,2,10,10,5,-1},
{2,1,7,10,5,1,7,10,2,-1},
{5,10,10, 2,7,7,2,1,1,-1} };
void spread(int x, int y, int d) {
	int total = A[x][y];
	for (int i = 0; i < 10; i++) {
		int nx = x + dx[d][i];
		int ny = y + dy[d][i];
		int ns = (A[x][y] * ds[d][i]) / 100;
		if (i == 9) ns = total;
		total -= ns;
		if (nx < 1 || nx > N || ny < 1 || ny > N) {
			sum += ns;
			continue;
		}
		A[nx][ny] += ns;
	}
}
void tornado() {
	int x = N / 2 + 1, y = N / 2 + 1;
	int len = 1;
	while (len < N) {
		for (int i = 1;i<=len;i++) { // ¿ÞÂÊÀ¸·Î È¦¼ö¹ø
			spread(x, y - 1, 0);
			A[x][y - 1] = A[x][y];
			y -= 1;
		}
		for (int i = 1; i <= len; i++) { // ¾Æ·¡·Î È¦¼ö¹ø
			spread(x + 1, y, 1);
			A[x + 1][y] = A[x][y];
			x += 1;
		}
		len++;
		for (int i = 1; i <= len; i++) { // ¿À¸¥ÂÊÀ¸·Î Â¦¼ö¹ø
			spread(x, y + 1, 2);
			A[x][y + 1] = A[x][y];
			y += 1;
		}
		for (int i = 1; i <= len; i++) { // À§·Î Â¦¼ö¹ø
			spread(x-1, y, 3);
			A[x - 1][y] = A[x][y];
			x -= 1;
		}
		len++;
	}
	for (int i = 1; i < len; i++) { // ¿ÞÂÊÀ¸·Î Â¦¼ö¹ø
		spread(x, y - 1, 0);
		A[x][y - 1] = A[x][y];
		y -= 1;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	tornado();
	cout << sum;
	return 0;
}