#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int T;
int main() {
	cin >> T;
	while (T--) {
		int M = 0;
		int P, Q, A, B, C, D;
		cin >> P >> Q >> A >> B >> C >> D;
		int coin = ((Q / C) * D); // trade berry for coin

		coin += ((P / A) * B); // trade bit for coin
		P %= A;

		int tradecnt = (coin - P) / (A + B);

		P += A * tradecnt;
		coin -= B * tradecnt;

		M = min(P, coin);
		
		if (coin >= B) M = max(M, min(P + A, coin - B));

		cout << M << '\n';
	}
	return 0;
}
