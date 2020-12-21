#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<map>
using namespace std;
int n, m, cnt, train[100002][21];
int arr[100002],chk[1<<21];
int main() {
	cin >> n >> m;
	for (int k = 1; k <= m; k++) {
		int a, b, c;
		cin >> a;
		if (a <= 2) {
			cin >> b >> c;
			if (a == 1) {
				if (!train[b][c]) {
					train[b][c] = 1;
					arr[b] += (1<<c);
				}
			}
			if (a == 2) {
				if (train[b][c]) {
					train[b][c] = 0;
					arr[b] -= (1 << c);
				}
			}
		}
		else {
			cin >> b;
			if (a == 3) {
				if (train[b][20]) {
					train[b][20] = 0;
					arr[b] -= (1 << 20);
				}
				for (int i = 19; i >=1; i--) {
					if (train[b][i]) {
						if (train[b][i + 1]) {
							arr[b] -= (1 << i);
							train[b][i] = 0;
						}
						else {
							arr[b] -= (1 << i);
							arr[b] += (1 << (i+1));
							train[b][i] = 0;
							train[b][i+1] = 1;
						}
					}
				}
			}
			if (a == 4) {
				if (train[b][1]) {
					train[b][1] = 0;
					arr[b] -= (1 << 1);
				}
				for (int i = 2; i <= 20; i++) {
					if (train[b][i]) {
						if (train[b][i - 1]) {
							arr[b] -= (1 << i);
							train[b][i] = 0;
						}
						else {
							arr[b] -= (1 << i);
							arr[b] += (1 << (i - 1));
							train[b][i] = 0;
							train[b][i - 1] = 1;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		//printf("%d\n",arr[i]);
		if (!chk[arr[i]]) {
			cnt++;
			chk[arr[i]] = 1;
		}
	}
	printf("%d", cnt);
	return 0;
}