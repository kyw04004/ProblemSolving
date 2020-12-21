#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int s, N, K, R1, R2, C1, C2, len = 1, p;
int go(int x, int y, int len, int time) {
	len /= N;
	if (time == 0) return 0;
	if (p*len<=x && p*len<=y && x<(p+K)*len && y<(p+K)*len)
		return 1;
	return go(x%len, y%len, len, time - 1);
}
int main()
{
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
	p = (N - K) / 2;
	for (int i = 1; i <= s; i++) len *= N;
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++)
			printf("%d", go(i, j, len, s));
		printf("\n");
	}
	return 0;
}