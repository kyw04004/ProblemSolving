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
string str;
int ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		for (int j = 2; j <= str.size()-i; j+=2) {
			string sub = str.substr(i,j);
			int a = 0, b = 0;
			for (int k = 0; k < sub.size()/2; k++) {
				a += sub[k] - '0';
				b += sub[sub.size() - 1 - k] - '0';
			}
			if(a==b) ans = max(ans, j);
		}
	}
	cout << ans;
	return 0;
}