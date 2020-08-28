#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, m, arr[100001];
int main() {
	int left = 0, right = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		left = max(left, arr[i]);
		right += arr[i];
	}
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (sum + arr[i] <= mid) sum += arr[i];
			else sum = arr[i], cnt++;
		}
		if (cnt <= m) right = mid - 1;
		else left = mid + 1;
	}
	cout << left;
	return 0;
}