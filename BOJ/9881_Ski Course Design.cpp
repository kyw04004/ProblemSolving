#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, ans = 1e9;
int height[1001];
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> height[i];
	sort(height, height + N);
	int dif = height[N - 1] - height[0];
	if (dif <= 17) ans = 0;
	else {
		int change = dif - 17;
		int cost;
		for (int i = 0; i <= change; i++) {
			cost = 0;
			int Min = height[0] + i;
			int Max = height[N - 1] - change + i;
			for (int j = 0; j < N; j++) {
				if (height[j] < Min) cost += (Min - height[j]) * (Min - height[j]);
				if (height[j] > Max) cost += (height[j] - Max) * (height[j] - Max);
			}
			ans = min(ans, cost);
		}
	}
	cout << ans;
	return 0;
}