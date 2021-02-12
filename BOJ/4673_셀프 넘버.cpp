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
int chk[10005];
void go(int val) {
	int com = val;
	while (com > 0) {
		val += com % 10;
		com /= 10;
	}
	if (val <= 10000) {
		chk[val] = 1;
		go(val);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 10000; i++)
		if (!chk[i]) go(i);
	for (int i = 1; i <= 10000; i++)
		if (!chk[i]) cout << i <<'\n';
	return 0;
}