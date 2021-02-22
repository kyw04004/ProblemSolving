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
queue<int> q;
stack<int> s;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int arr[105], n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	int com = arr[2] - arr[1];
	for (int i = 2; i <= n - 1; i++)
		com = gcd(com, arr[i + 1] - arr[i]);
	s.push(com);
	for (int i = 2; i <= sqrt(com); i++)
		if (com % i == 0) {
			q.push(i);
			if (i == (com / i)) continue;
			s.push(com / i);
		}
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}