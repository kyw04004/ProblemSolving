#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool possible(int val, vector<int> arr, int k) {
	int Max = 0;
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = max(0, arr[i] - val);
		if (arr[i] == 0) cnt++, Max = max(Max, cnt);
		else cnt = 0;
	}
	return Max < k;
}
int solution(vector<int> stones, int k) {
	int answer = 0;
	int left = 1, right = 2e8;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (possible(mid, stones, k)) {
			answer = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return answer + 1;
}