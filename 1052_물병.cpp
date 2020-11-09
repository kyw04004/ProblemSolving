#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<map>
using namespace std;
int n, k, ans,com=1;
int arr[25];
int main() {
	cin >> n >> k;
	for (int i = 0; i <= 24; i++) {
		arr[i] = com;
		com *= 2;
	}
	while (1) {
		int nn = n;
		int cnt = 0;
		for (int i = 24; i >=0; i--) {
			if (nn >= arr[i]) {
				nn -= arr[i];
				cnt++;
			}
		}
		if (cnt <= k) {
			printf("%d\n", ans);
			break;
		}
		else {
			ans++;
			n++;
		}
	}
	return 0;
}