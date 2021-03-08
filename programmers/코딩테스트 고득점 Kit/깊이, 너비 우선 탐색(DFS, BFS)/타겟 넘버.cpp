#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int ans;
void go(int now, int sum, int size, int tar, vector<int> numbers) {
	if (now == size) {
		if (sum == tar) ans++;
		return;
	}
	go(now + 1, sum + numbers[now], size, tar, numbers);
	go(now + 1, sum - numbers[now], size, tar, numbers);
}
int solution(vector<int> numbers, int target) {
	go(0, 0, numbers.size(), target, numbers);
	cout << ans;
	return ans;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> v = { 1,1,1,1,1 };
	solution(v, 3);
	return 0;
}