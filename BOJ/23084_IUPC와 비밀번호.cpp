#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
string S;
int N, alphaCnt[26];
bool can_password(string T) {
	int comCnt[26] = {0,};
	int diffCnt = 0;
	int oneDif = 0;
	if (T.size() < S.size()) return false;

	if (T.size() == S.size()) {
		for (int i = 0; i < T.size(); i++)
			comCnt[T[i] - 'a']++;
		for (int i = 0; i < 26; i++) {
			if (alphaCnt[i] != comCnt[i]) diffCnt++;
			if(abs(alphaCnt[i] - comCnt[i]) == 1) oneDif++;
		}
		if (diffCnt == 2 && oneDif == 2) return true;
		else return false;
	}

	else {
		for (int i = 0; i < S.size(); i++)
			comCnt[T[i] - 'a']++;
		for (int i = 0; i < 26; i++) {
			if (alphaCnt[i] != comCnt[i]) diffCnt++;
			if (abs(alphaCnt[i] - comCnt[i]) == 1) oneDif++;
		}
		if (diffCnt == 2 && oneDif == 2) return true;
		else if (diffCnt == 0 && oneDif == 0) return true;
		else {
			for (int i = S.size(); i < T.size(); i++) {
				comCnt[T[i - S.size()] - 'a']--;
				comCnt[T[i] - 'a']++;
				diffCnt = 0;
				oneDif = 0;
				for (int j = 0; j < 26; j++) {
					if (alphaCnt[j] != comCnt[j]) diffCnt++;
					if (abs(alphaCnt[j] - comCnt[j]) == 1) oneDif++;
				}
				if (diffCnt == 2 && oneDif == 2) return true;
				if (diffCnt == 0 && oneDif == 0) return true;
			}
			return false;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> S >> N;
	for (int i = 0; i < S.size(); i++)
		alphaCnt[S[i] - 'a']++;
	for (int i = 0; i < N; i++) {
		string T; cin >> T;
		if (can_password(T)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}