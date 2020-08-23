#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, m, k, arr[51][51], Max;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char input;
			cin >> input;
			arr[i][j] = input - '0';
		}
	cin >> k;
	for (int i = 1; i <= n; i++) {
		int zero = 0;
		int cnt = 0;
		for (int j = 1; j <= m; j++)
			if (!arr[i][j]) zero++;
		if (zero <= k && zero % 2 == k % 2)
			for (int a = 1; a <= n; a++) {
				int ok = 1;
				for (int b = 1; b <= m; b++)
					if (arr[i][b] != arr[a][b]) ok = 0;
				if (ok == 1) cnt++;
			}
		Max = max(Max, cnt);
	}
	cout << Max;
	return 0;
}