#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
string quack;
int q, u, a, c, k,cnt;
int main() {
	cin >> quack;
	for (int i = 0; i < quack.size(); i++) {
		if (quack[i] == 'q') q++;
		if (quack[i] == 'u') u++;
		if (quack[i] == 'a') a++;
		if (quack[i] == 'c') c++;
		if (quack[i] == 'k') k++;
	}
	for (int i = 0; i < quack.size(); i++) {
		if (quack[i] == 'q') {
			quack[i] = 'X';
			char now = 'q';
			for (int j = i + 1; j < quack.size(); j++) {
				if (now == 'q' && quack[j] == 'u') now = 'u', quack[j] = 'X';
				else if (now == 'u' && quack[j] == 'a') now = 'a', quack[j] = 'X';
				else if (now == 'a' && quack[j] == 'c') now = 'c', quack[j] = 'X';
				else if (now == 'c' && quack[j] == 'k') now = 'k', quack[j] = 'X';
				else if (now == 'k' && quack[j] == 'q') now = 'q', quack[j] = 'X';
			}
			if (now == 'k') cnt++;
			else {
				cnt = -1;
				break;
			}
		}
	}
	if (q == u && u == a && a == c && c == k)
		cout << cnt;
	else
		cout << -1;
	return 0;
}