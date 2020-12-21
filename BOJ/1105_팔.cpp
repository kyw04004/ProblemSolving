#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
string st, en, ans;
int cnt;
int main() {
	cin >> st >> en;
	for (int i = 0; i < en.size(); i++) {
		if (st.size() == en.size() && en[i] == st[i]) {
			if(st[i]-'0'==8) cnt++;
		}
		else break;
	}
	cout << cnt;
	return 0;
}