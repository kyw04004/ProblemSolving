#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int N, r, c, cnt;
void go(int x, int y, int Size) {
	if (Size == 2) {
		if (x == r && y == c) { cout << cnt; return; } cnt++;
		if (x == r && y + 1 == c) { cout << cnt; return; } cnt++;
		if (x + 1 == r && y == c) { cout << cnt; return; } cnt++;
		if (x + 1 == r && y + 1 == c) { cout << cnt; return; } cnt++;
		return;
	}
	if (x <= r && r < x + Size / 2 && y <= c && c < y + Size / 2) go(x, y, Size / 2);
	else cnt += Size*Size/4;
	if (x <= r && r < x + Size / 2 && y + Size / 2 <= c && c < y + Size) go(x, y + Size / 2, Size / 2);
	else cnt += Size * Size / 4;
	if (x + Size / 2 <= r && r < x + Size && y <= c && c < y + Size / 2) go(x + Size / 2, y, Size / 2);
	else cnt += Size * Size / 4;
	if (x + Size / 2 <= r && r < x + Size && y + Size / 2 <= c && c < y + Size) go(x + Size / 2, y + Size / 2, Size / 2);
	else cnt += Size * Size / 4;
}
int main() {
	cin >> N >> r >> c;
	N = (1 << N);
	go(0, 0, N);
	return 0;
}