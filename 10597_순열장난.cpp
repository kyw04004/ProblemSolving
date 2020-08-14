#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
stack <int> s;
string str;
int chk[51], ans[51],Max,ok,cnt;
void dfs(int num, int depth) {
	if (depth > str.size()) {
		ok = 1;
		return;
	}
	int now = str[depth] - '0';
	int now2 = str[depth + 1] - '0';
	int now3 = now * 10 + now2;
	if (!chk[now]) {
		chk[now] = 1;
		dfs(now, depth + 1);
		if(ok==0) chk[now] = 0;
	}
	if (!chk[now3] && now3 <= Max && depth+1<str.size()) {
		chk[now3] = 1;
		dfs(now3, depth + 2);
		if (ok == 0) chk[now3] = 0;
	}
	if (ok == 1 && cnt<Max) {
		s.push(num);
		cnt++;
	}
}
int main() {
	cin >> str;
	if (str.size() < 10) Max = str.size();
	else Max = 9 + ((str.size() - 9) / 2);
	dfs(str[0]-'0', 0);
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}