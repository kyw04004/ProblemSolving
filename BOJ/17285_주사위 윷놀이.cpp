#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int diceVal[11], ans;
void calcMax(vector<int> seq) {
	int hL[5] = {};
	int score = 0;
	for (int i = 0; i < 10; i++) {
		int horse = seq[i];
		int cnt = diceVal[i];
		if (hL[horse] == 100) break;
		if (hL[horse] == 0 || (hL[horse] % 5 != 0 && hL[horse] <= 20)) {
			hL[horse] += cnt;
			if (hL[horse] > 20) hL[horse] = 100;
		}
		else {
			if (hL[horse] == 5) {
				if (cnt < 4) hL[horse] = 30 + cnt;
				else hL[horse] = 36 + cnt;
			}
			else if (hL[horse] == 10) {
				if (cnt < 3) hL[horse] = 33 + cnt;
				else hL[horse] = 37 + cnt;
			}
			else if (hL[horse] == 15) {
				if (cnt < 4) hL[horse] = 35 + cnt;
				else hL[horse] = 36 + cnt;
			}
			else if (hL[horse] == 20) hL[horse] = 100;
			else if (hL[horse] / 10 == 3) {
				if (hL[horse] % 10 < 4) {
					hL[horse] += cnt;
					if (hL[horse] > 33) hL[horse] += 6;
				}
				else if (hL[horse] % 10 < 6) {
					hL[horse] += cnt;
					if (hL[horse] > 35) hL[horse] += 4;
				}
				else {
					hL[horse] += cnt;
					if (hL[horse] > 38) hL[horse] += 1;
				}
			}
			else hL[horse] += cnt;
		}
		if (hL[horse] == 43) hL[horse] = 20;
		if (hL[horse] > 43) hL[horse] = 100;
		if (hL[horse] <= 20) score += 2 * hL[horse];
		else {
			if (hL[horse] == 31) score += 13;
			if (hL[horse] == 32) score += 16;
			if (hL[horse] == 33) score += 19;
			if (hL[horse] == 34) score += 22;
			if (hL[horse] == 35) score += 24;
			if (hL[horse] == 36) score += 28;
			if (hL[horse] == 37) score += 27;
			if (hL[horse] == 38) score += 26;
			if (hL[horse] == 40) score += 25;
			if (hL[horse] == 41) score += 30;
			if (hL[horse] == 42) score += 35;
		}
		for (int j = 1; j <= 4; j++) {
			if (horse == j) continue;
			if (hL[j] == 0 || hL[j] == 100) continue;
			if (hL[j] == hL[horse]) {
				score = -1e9;
				i=100,j=100;
			}
		}
	}
	ans = max(ans, score);
}
void makeSeq(vector<int> seq) {
	if (seq.size() == 10) {
		calcMax(seq);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		seq.push_back(i);
		makeSeq(seq);
		seq.pop_back();
	}
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 10; i++) cin >> diceVal[i];
	vector<int> v;
	makeSeq(v);
	cout << ans;
	return 0;
}