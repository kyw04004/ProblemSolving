#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int A, B,chk[11],C = -1;
vector<int> v;
void go(int num, int depth) {
	if (num >= B) return;
	if (depth == v.size()) {
		C = max(C, num);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (depth == 0 && v[i] == 0) continue;
		if (!chk[i]) {
			chk[i] = 1;
			go(10 * num + v[i],depth + 1);
			chk[i] = 0;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> A >> B;
	while (A) {
		v.push_back(A % 10);
		A /= 10;
	}
	sort(v.begin(), v.end());
	go(0,0);
	cout << C << '\n';
	return 0;
}