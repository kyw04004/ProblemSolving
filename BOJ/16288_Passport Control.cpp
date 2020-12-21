#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int n, k, arr[101],cnt=1;
vector <int> v[101];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	v[1].push_back(arr[1]);
	for (int i = 2; i <= n; i++) {
		int ok = 0;
		for (int j = 1; j <= cnt; j++) {
			if (v[j][v[j].size() - 1] < arr[i]) {
				v[j].push_back(arr[i]);
				ok = 1;
				break;
			}
		}
		if (ok == 0) {
			v[cnt + 1].push_back(arr[i]);
			cnt+=1;
		}
	}
	if (cnt > k) cout << "NO";
	else cout << "YES";
	return 0;
}