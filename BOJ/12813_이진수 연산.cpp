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
char A[100005], B[100005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 100000; i++) cin >> A[i];
	for (int i = 0; i < 100000; i++) cin >> B[i];
	for (int i = 0; i < 100000; i++) {
		if (A[i]=='1' && A[i] == B[i]) cout << 1;
		else cout << 0;
	}
	cout << '\n';
	for (int i = 0; i < 100000; i++) {
		if (A[i]=='1' || B[i]=='1') cout << 1;
		else cout << 0;
	}
	cout << '\n';
	for (int i = 0; i < 100000; i++) {
		if (A[i] == '1' && B[i] == '1') cout << 0;
		else if (A[i] == '0' && B[i] == '0') cout << 0;
		else cout << 1;
	}
	cout << '\n';
	for (int i = 0; i < 100000; i++) {
		if (A[i] == '1') cout << 0;
		else cout << 1;
	}
	cout << '\n';
	for (int i = 0; i < 100000; i++) {
		if (B[i] == '1') cout << 0;
		else cout << 1;
	}
	cout << '\n';
	return 0;
}