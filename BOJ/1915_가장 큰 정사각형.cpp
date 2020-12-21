#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, m, arr[1005][1005],ans,Min;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char input;
			cin >> input;
			arr[i][j] = input - '0';
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] != 0) {
				Min = min(arr[i - 1][j], arr[i][j - 1]);
				Min = min(Min, arr[i - 1][j - 1]);
				arr[i][j] = Min + 1;
			}
			ans = max(ans, arr[i][j]);
		}
	cout << ans * ans;
	return 0;
}