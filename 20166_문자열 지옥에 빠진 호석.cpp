#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
int n, m, k, ans[1001];
int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,0,-1,1,0,-1,1 };
char arr[11][11];
map<string, int> M;
vector<string> godlike;
string str;
void go(int x, int y, string str) {
	if (str.size() > 5) return;
	if (M[str]>=0) M[str]++;
	for (int i = 0; i < 8; i++) {
		int nx = (x + dx[i] + n) % n;
		int ny = (y + dy[i] + m) % m;
		go(nx, ny, str + arr[nx][ny]);
	}
	return;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= k; i++) {
		string s;
		cin >> s;
		M[s] = 0;
		godlike.push_back(s);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			string s;
			s+=arr[i][j];
			go(i, j, s);
		}
	for (int i = 0; i < k; i++)
		cout << M[godlike[i]] << "\n";
	return 0;
}