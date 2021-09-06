#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
int N, M;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	cout << M - gcd(N, M);
	return 0;
}

