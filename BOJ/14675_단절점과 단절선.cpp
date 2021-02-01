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
int in[100005], out[100005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		out[a]++, in[b]++;
		out[b]++, in[a]++;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >>b;
		if (a == 1) {
			if (out[b]*in[b]==1) cout << "no\n";
			else cout << "yes\n";
		}
		else cout << "yes\n";
	}
	return 0;
}