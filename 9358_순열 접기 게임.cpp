#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int t, n;
int main() {
	cin >> t;
	for (int test = 1; test <= t; test++) {
		cin >> n;
		int arr[101], size = n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		while (size > 2) {
			for (int i = 0; i < (size + 1) / 2; i++) 
				arr[i] = arr[i] + arr[size - i - 1];
			size = (size + 1) / 2;
		}
		if (arr[0] > arr[1]) printf("Case #%d: Alice\n", test);
		else printf("Case #%d: Bob\n", test);
	}
	return 0;
}