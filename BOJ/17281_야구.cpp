#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int N, attack[51][10], chk[10], Max;
void make_max(vector<int> seq) {
	int out = 0;
	int bat = 0;
	int b[4] = {0, };
	int inn = 1;
	int score = 0;
	while(inn <= N) {
		if (attack[inn][seq[bat]] == 0) out++;
		else if (attack[inn][seq[bat]] == 1) {
			if (b[3]) score++, b[3] = 0;
			if (b[2]) b[2] = 0, b[3] = 1;
			if (b[1]) b[1] = 0, b[2] = 1;
			b[1] = 1;
		}
		else if (attack[inn][seq[bat]] == 2) {
			for (int i = 3; i >= 2; i--) if (b[i]) b[i] = 0, score++;
			if (b[1]) b[1] = 0, b[3] = 1;
			b[2] = 1;
		}
		else if (attack[inn][seq[bat]] == 3) {
			for (int i = 3; i >= 1; i--) if (b[i]) b[i] = 0, score++;
			b[3] = 1;
		}
		else {
			for (int i = 3; i >= 1; i--) if (b[i]) b[i] = 0, score++;
			score++;
		}
		bat = (bat + 1) % 9;
		if (out == 3) {
			inn++;
			out = 0;
			memset(b, 0, sizeof(b));
		}
	}
	Max = max(Max, score);
}
void make_seq(int index, vector<int> seq) {
	if (index == 9) {
		make_max(seq);
		return;
	}
	if (index == 3) {
		seq.push_back(1);
		chk[1] = 1;
		make_seq(index + 1, seq);
		chk[1] = 0;
		seq.pop_back();
	}
	else {
		for (int i = 2; i <= 9; i++) {
			if (chk[i] == 0) {
				chk[i] = 1;
				seq.push_back(i);
				make_seq(index + 1, seq);
				seq.pop_back();
				chk[i] = 0;
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 9; j++)
			cin >> attack[i][j];
	vector<int> v;
	make_seq(0, v);
	cout << Max;
	return 0;
}