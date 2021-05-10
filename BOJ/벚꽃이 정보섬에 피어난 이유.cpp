#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n, arr[11], ans;
int mul(int s, int e) {
	int sum = 1;
	for (int i = s; i <= e; i++)
		sum *= arr[i];
	return sum;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int a = 1; a <= n - 3; a++)
		for (int b = 1; b <= n - 3; b++)
			for (int c = 1; c <= n - 3; c++)
				for (int d = 1; d <= n - 3; d++) {
					if (a + b + c + d != n) continue;
					int Max = mul(1, a) + mul(a + 1, a + b) + mul(a + b + 1, a + b + c) + mul(a + b + c + 1, a + b + c + d);
					ans = max(ans, Max);
				}

	cout << ans;
	return 0;
}