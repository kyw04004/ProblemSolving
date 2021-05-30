#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll N, com = 9, cnt[9][27],alphaNum[27], sum;
pair<ll, int> alpha[27];
map<int, int> m;
string input[11];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) { // 입력받고 자릿수마다 알파벳 갯수세주기
		cin >> input[i];
		ll len = input[i].size();
		for (int j = 0; j < len; j++)
			cnt[len-j][input[i][j] - 'A']++;
	}

	for (int i = 8; i >= 1; i--) //알파벳을 특수숫자로 변형
		for (int j = 0; j < 26; j++) {
			alpha[j].first += cnt[i][j] * pow(10, i - 1);
			alpha[j].second = j;
		}

	sort(alpha, alpha + 26); // 정렬

	for (int i = 25; i >=0 ; i--)
		alphaNum[alpha[i].second] = com--;//알파벳에 자연수 매핑

	for (int i = 0; i < N; i++) { // 값 연산
		ll len = input[i].size();
		for (int j = 0; j < len; j++)
			sum += alphaNum[input[i][j] - 'A'] * pow(10, len - j - 1);
	}

	cout << sum;
	return 0;
}