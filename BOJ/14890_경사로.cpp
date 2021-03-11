#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
int N, L, board[105][105], sum;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	for (int i = 1; i <= N; i++) {
		int pos = 1;
		int edge[105];
		for (int j = 1; j <= N; j++) edge[j] = board[i][j];
		for (int j = 1; j < N; j++) {
			if(edge[j] == edge[j + 1]) continue;
			else if (edge[j] + 1 == edge[j + 1]) {
				int ok = 1;
				if (j - L + 1 < 1) {
					pos = 0;
					break;
				}
				else {
					for (int k = j; k > j - L + 1; k--)
						if (edge[k] != edge[k - 1]) ok = 0;
				}
				if(!ok) {
					pos = 0;
					break;
				}
			}
			else if (edge[j] == edge[j + 1] + 1) {
				int ok = 1;
				if(j+L > N) {
					pos = 0;
					break;
				}
				for (int k = j + 1; k < j + L; k++)
					if (edge[k] != edge[k + 1]) ok = 0;
				if (!ok) {
					pos = 0;
					break;
				}
				else {
					if (j + L == N) break;
					else if (edge[j + L] != edge[j + L + 1]) {
						if (edge[j + L] == edge[j + L + 1] + 1) {
							j += (L - 1);
						}
						else {
							pos = 0;
							break;
						}
					}
					else {
						for (int k = j + 1; k <= j + L; k++) edge[k] = 11;
						j += L;
					}
				}
			}
			else {
				pos=0;
				break;
			}
		}
		sum += pos;
	}


	for (int j = 1; j <= N; j++) {
		int pos = 1;
		int edge[105];
		for (int i = 1; i <= N; i++) edge[i] = board[i][j];
		for (int i = 1; i < N; i++) {
			if (edge[i] == edge[i + 1]) continue;
			else if (edge[i] + 1 == edge[i + 1]) {
				int ok = 1;
				if (i - L + 1 < 1) {
					pos = 0;
					break;
				}
				else {
					for (int k = i; k > i - L + 1; k--)
						if (edge[k] != edge[k - 1]) ok = 0;
				}
				if (!ok) {
					pos = 0;
					break;
				}
			}
			else if (edge[i] == edge[i + 1] + 1) {
				int ok = 1;
				if (i + L > N) {
					pos = 0;
					break;
				}
				for (int k = i + 1; k < i + L; k++)
					if (edge[k] != edge[k + 1]) ok = 0;
				if (!ok) {
					pos = 0;
					break;
				}
				else {
					if (i + L == N) break;
					else if (edge[i + L] != edge[i + L + 1]) {
						if (edge[i + L] == edge[i + L + 1] + 1) {
							i += (L-1);
						}
						else {
							pos = 0;
							break;
						}
					}
					else {
						for (int k = i + 1; k <= i + L; k++) edge[k] = 11;
						i += L;
					}
				}
			}
			else {
				pos = 0;
				break;
			}
		}
		sum += pos;
	}
	cout << sum;
	return 0;
}