#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int n, arr[1005], chk[1005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) cin >> arr[i];
	int st = 0;
	while (1) {
		memset(chk, 0, sizeof(chk));
		int possible = 1;
		int index = 1;
		st++;
		vector<int> v;
		if (!chk[st]) {
			chk[st] = 1;
			v.push_back(st);
		}
		int val = arr[index] - st;
		if (!chk[val] && val >= 1 && val <= n) {
			chk[val] = 1;
			v.push_back(val);
		}
		else {
			possible = 0;
			continue;
		}
		while (v.size() < n) {
			index++;
			val = arr[index] - val;
			if (!chk[val] && val >= 1 && val <= n) {
				chk[val] = 1;
				v.push_back(val);
			}
			else {
				possible = 0;
				break;
			}
		}
		if (possible) {
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << ' ';
			break;
		}
	}
	return 0;
}