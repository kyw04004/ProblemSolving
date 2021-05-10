#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int N, L, arr[1005], cnt = 1, End;
int main() {
	cin >> N >> L;
	L *= 2;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i] *= 2;
	}
	sort(arr, arr + N);
	End = arr[0] - 1 + L;
	for (int i = 1; i < N; i++) {
		if (End >= arr[i] + 1) continue;
		cnt++;
		End = max(arr[i] - 1 + L, End + L);
	}
	cout << cnt;
	return 0;
}