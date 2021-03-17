#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int N, K;
string str[101];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> str[i];
	string s = "";
	int index = 1, space = 0;
	while (index <= N) {
		if (s.size() + str[index].size() - space <= K) {
			s += str[index];
			s += ' ';
			space++;
			index++;
		}
		else {
			cout << s.substr(0, s.size() - 1) << '\n';
			s = "";
			space = 0;
		}
	}
	cout << s.substr(0, s.size() - 1);
	return 0;
}