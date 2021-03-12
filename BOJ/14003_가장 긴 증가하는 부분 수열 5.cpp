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
int n, arr[1000005];
int parent[1000005];
vector<int> v;
stack<int> s;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	parent[0] = 1;
	v.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
			parent[i] = v.size();
		}
		else {
			int it = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[it] = arr[i];
			parent[i] = it + 1;
		}
	}
	cout << v.size() << '\n';
	int index = v.size();
	for (int i = n - 1; i >= 0; i--) {
		if (index == 0) break;
		if (parent[i] == index) {
			s.push(arr[i]);
			index--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}