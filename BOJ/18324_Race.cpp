#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int K, N, X[100005],Min=1e9;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> K >> N;
	for (int i = 1; i <= N; i++) cin >> X[i];
	for (int i = 1; i <= N; i++) {
		int time=0, sum = 0, speed = 0;
		while (speed < X[i] && sum < K) {
			speed++;
			time++;
			sum += speed;
		}
		if (sum < K) {
			time++;
			sum += speed;
		}
		while (sum < K) {
			time+=2;
			speed++;
			sum += speed * 2;
		}
		if (sum - speed >= K) time--;
		cout << time << '\n';
	}
	return 0;
}