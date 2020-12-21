#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
int t, n;
string str;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> n;
		cin >> str;
		for (int i = str.size() - 1; i >= 0; i--) {
			if (str[i] == ')') cnt++;
			else break;
		}
		if (cnt > str.size() / 2) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}