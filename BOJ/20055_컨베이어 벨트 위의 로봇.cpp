#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int N, K, conveyor[201], robot[201], step, robotN;
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) cin >> conveyor[i];
	while (1) {
		step++;
		//first step
		int lastR = robot[2 * N - 1], lastC = conveyor[2 * N - 1];
		for (int i = 2 * N - 1; i >= 1; i--) {
			robot[i] = robot[i - 1];
			conveyor[i] = conveyor[i - 1];
		}
		robot[0] = lastR, conveyor[0] = lastC;
		if (robot[N - 1]) robot[N - 1] = 0;
		//second step
		for (int i = 2 * N - 1; i >= 0; i--) {
			int next = (i + 1) % (2 * N);
			if (robot[i] && !robot[next] && conveyor[next]) {
				conveyor[next]--;
				robot[next] = robot[i];
				robot[i] = 0;
			}
		}
	
		if (robot[N - 1]) robot[N - 1] = 0;
		//third step
		if (conveyor[0] >= 1) {
			conveyor[0]--;
			robot[0] = ++robotN;
		}
		//fourth step
		int cnt = 0;
		for (int i = 0; i < 2 * N; i++)
			if (conveyor[i] == 0) cnt++;
		if (cnt >= K) break;
	}
	cout << step;
	return 0;
}