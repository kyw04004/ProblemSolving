#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
int n, w, l, time, sum;
queue<int> input;
queue <int> bridge;
int main() {
	cin >> n >> w >> l;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		input.push(a);
	}
	while (!input.empty()) {
		if (bridge.size() == w) {
			sum -= bridge.front();
			bridge.pop();
		}
		time++;
		if (sum + input.front() <= l) {
			sum += input.front();
			bridge.push(input.front());
			input.pop();
		}
		else bridge.push(0);		
	}
	time += w;
	cout << time;
	return 0;
}