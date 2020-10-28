#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
string str;
int ans = 1;
int chk[5001];
int main() {
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') chk[i] = 1, ans++;
		if (str[i] == '-')  chk[i] = 1, ans++;
		if (str[i] == '\'') {
			char c = str[i + 1];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'h') {
				if (i - 2 == -1 || chk[i - 2]) {
					if (str[i - 1] == 'c') chk[i] = 1, ans++;
					if (str[i - 1] == 'j') chk[i] = 1, ans++;
					if (str[i - 1] == 'n') chk[i] = 1, ans++;
					if (str[i - 1] == 'm') chk[i] = 1, ans++;
					if (str[i - 1] == 't')chk[i] = 1, ans++;
					if (str[i - 1] == 's')chk[i] = 1, ans++;
					if (str[i - 1] == 'l') chk[i] = 1, ans++;
					if (str[i - 1] == 'd')chk[i] = 1, ans++;
				}
				if (i - 3 == -1 || chk[i - 3])
					if (str[i - 2] == 'q' && str[i - 1] == 'u') chk[i] = 1, ans++;
			}
		}
	}
	cout << ans;
	return 0;
}