#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
bool Possible(ll val, int n, vector<int> times) {
	int index = 0;
	while (index < times.size()) {
		n -= (val / times[index]);
		index++;
		if (n <= 0) return true;
	}
	return false;
}
ll BinarySearch(int n, vector<int> times) {
	ll left = 0, right = (ll)n * (ll)times[0], ans;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (Possible(mid, n, times)) ans = mid, right = mid - 1;
		else left = mid + 1;
	}
	return ans;
}
long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());
	long long answer = BinarySearch(n, times);
	return answer;
}