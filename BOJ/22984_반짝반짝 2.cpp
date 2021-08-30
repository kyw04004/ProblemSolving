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
int N;
double arr[100005], sum;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	if (N == 1) {
		cout << arr[0];
		return 0;
	}
	for (int i = 0; i < N - 1; i++) {
		double first = arr[i];
		double second = arr[i + 1];
		sum += first * second * 2;
		sum += (1.0 - first) * second * 2;
		sum += first * (1.0 - second) * 2;
	}
	for (int i = 1; i < N - 1; i++) sum -= arr[i];
	cout << fixed;
	cout.precision(6);
	cout << sum;
	return 0;
}

