#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n, sum=0,tree[100001], msum=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		sum += tree[i];
		msum += (tree[i] / 2);
	}
	if (sum % 3 == 0 && (sum / 3) <= msum) cout << "YES";
	else cout << "NO";
	return 0;
}