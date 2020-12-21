#include<iostream>
#include<istream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
int n, a, input[1001][21], cnt, sum[21], chk[21];
int first[21]; 
string name[21];
int main() {
	cin >> n;
	getchar();
	for (int i = 1; i <= n; i++) getline(cin, name[i]);
	while (cin >> a) {
		cnt += 1;
		input[cnt][1] = a;
		sum[a] += 1;
		if (!first[a]) first[a] = cnt;
		for (int i = 2; i <= n; i++) cin >> input[cnt][i];
	}
	while (1) {
		int Max = -1, Maxindex, equal = 1; 
		for (int i = 1; i <= n; i++) { 
			if (chk[i]) continue;
			for (int j = 1; j <= n; j++) {
				if (chk[j]) continue;
				if (sum[i] != sum[j]) equal = 0;
			}
		}
		if (equal) { 
			for (int i = 1; i <= n; i++)
				if (!chk[i]) cout << name[i] << "\n";
			break;
		}
		for (int i = 1; i <= n; i++) 
			if (!chk[i] && sum[i] > Max) Max = sum[i], Maxindex = i;
		if (2 * Max > cnt) { 
			cout << name[Maxindex];
			break;
		}
		else { 
			int Min = 1e9, candi[21] = { 0, };
			for (int i = 1; i <= n; i++)
				if (!chk[i] && sum[i] < Min) Min = sum[i];
			for (int i = 1; i <= n; i++)
				if (!chk[i] && sum[i] == Min) candi[i] = 1;

			for (int k = 1; k <= n; k++) {
				if (candi[k]) {
					for (int i = 2; i <= n; i++) {
						if (chk[input[first[k]][i]]||candi[input[first[k]][i]]) continue;
						sum[input[first[k]][i]] += sum[k];
						chk[k] = 1;
						break;
					}
				}
			}
		}
	}
	return 0;
}