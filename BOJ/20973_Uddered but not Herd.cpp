#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
string a, b;
int cnt;
int bindex = 0;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	while (bindex < b.size()) {
		cnt++;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[bindex]) bindex++;
			if (bindex == b.size()) break;
		}
	}
	cout << cnt;
	return 0;
}