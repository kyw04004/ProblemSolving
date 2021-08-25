#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
int MPP = 1003001;
int N, prime[1003005];
vector<int> palinPrime;
void calcPrime() {
	for (int i = 2; i <= MPP; i++) prime[i] = 1;
	for (int i = 2; i * i <= MPP; i++)
		for (int j = i * i; j <= MPP; j += i)
			prime[j] = 0;
	for (int i = 2; i <= MPP; i++) {
		if (!prime[i]) continue;
		string str = to_string(i);
		bool palindrome = true;
		for (int j = 0; j < str.size() / 2; j++) {
			if (str[j] == str[str.size() - j - 1]) continue;
			else palindrome = false;
		}
		if (palindrome) palinPrime.push_back(i);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	calcPrime();
	cin >> N;
	for(int i=0;i<palinPrime.size();i++)
		if (palinPrime[i] >= N) {
			cout << palinPrime[i];
			break;
		}
	return 0;
}