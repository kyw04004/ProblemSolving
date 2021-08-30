#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
ll N, dice[6], three = 1e9, two = 1e9, Max, Min = 1e9, sum;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
		Max = max(Max, dice[i]);
		Min = min(Min, dice[i]);
		sum += dice[i];
	}
	if (N == 1) sum -= Max;
	else {
		sum = 0;
		three = min(three, dice[0] + dice[1] + dice[2]);
		three = min(three, dice[0] + dice[1] + dice[3]);
		three = min(three, dice[0] + dice[4] + dice[2]);
		three = min(three, dice[0] + dice[4] + dice[3]);
		three = min(three, dice[1] + dice[5] + dice[2]);
		three = min(three, dice[1] + dice[5] + dice[3]);
		three = min(three, dice[4] + dice[5] + dice[2]);
		three = min(three, dice[4] + dice[5] + dice[3]);
		two = min(two, dice[0] + dice[1]);
		two = min(two, dice[0] + dice[4]);
		two = min(two, dice[0] + dice[3]);
		two = min(two, dice[0] + dice[2]);
		two = min(two, dice[1] + dice[2]);
		two = min(two, dice[1] + dice[3]);
		two = min(two, dice[1] + dice[5]);
		two = min(two, dice[2] + dice[4]);
		two = min(two, dice[2] + dice[5]);
		two = min(two, dice[3] + dice[4]);
		two = min(two, dice[3] + dice[5]);
		two = min(two, dice[4] + dice[5]);
		sum += three * 4;
		sum += two * 4 * (N - 2);
		sum += (N - 2) * (N - 2) * Min;
		sum += (N - 1) * 4 * two;
		sum += (N - 2) * (N - 1) * 4 * Min;
	}
	cout << sum;
	return 0;
}

