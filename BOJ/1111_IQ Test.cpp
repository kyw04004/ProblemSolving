#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int n, arr[51];
vector<pair<int, int>> v;
vector<int> ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n == 1) cout << "A";
	else if (n == 2) {
		if (arr[0] == arr[1]) cout << arr[0];
		else cout << "A";
	}
	else {
		int chk = 1;
		int dif1 = arr[1] - arr[0];
		int dif2 = arr[2] - arr[1];
		int a;
		if (dif1 == 0) a = 0;
		else a = dif2 / dif1;
		int b = arr[1] - a * arr[0];
		for (int i = 0; i < n - 1; i++)
			if (a*arr[i]+b != arr[i + 1]) chk = 0;
		if(chk) cout << a * arr[n - 1] + b;
		else cout << "B";
	}
	return 0;
}