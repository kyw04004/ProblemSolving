#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int H, W, X, Y, arr[605][605];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> H >> W >> X >> Y;
	for (int i = 1; i <= H + X; i++)
		for (int j = 1; j <= W + Y; j++)
			cin >> arr[i][j];
	for (int i = 1 + X; i <= H; i++)
		for (int j = 1 + Y; j <= W; j++)
			arr[i][j] -= arr[i - X][j - Y];
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}