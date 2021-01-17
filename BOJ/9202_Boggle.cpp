#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,0,-1,1,0,-1};
int chk[10][10],schk[300005];
char arr[5][5];
int ans;
vector<string> input;
map <string, int> m;
struct Trie {
	bool finish;
	Trie* child[26];
	Trie() {
		fill(child, child + 26, nullptr);
		finish = false;
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (child[i]) delete child[i];
	}
	void insert(const char* key) {
		if (*key == NULL) {
			finish = true;
			return;
		}
		else {
			int next = *key - 'A';
			if (child[next] == NULL) child[next] = new Trie;
			child[next]->insert(key + 1);
		}
	}
	bool exist(const char* key) {
		if (*key == NULL) {
			if (finish) return true;
			return false;
		}
		int next = *key - 'A';
		if (child[next] == NULL) return false;
		return child[next]->exist(key + 1);
	}
};
Trie* trie = new Trie;
void Boggle(int x, int y, string s) {
	if (s.size() > 8) return;
	if (!schk[m[s]] && trie->exist(s.c_str())) {
		schk[m[s]] = 1;
		if (s.size() == 3) ans += 1;
		else if (s.size() == 4) ans += 1;
		else if (s.size() == 5) ans += 2;
		else if (s.size() == 6) ans += 3;
		else if (s.size() == 7) ans += 5;
		else if (s.size() == 8) ans += 11;
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (chk[nx][ny] || nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
		chk[nx][ny] = 1;
		Boggle(nx, ny, s + arr[nx][ny]);
		chk[nx][ny] = 0;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int w; cin >> w;
	for (int i = 0; i < w; i++) {
		string str;
		cin >> str;
		input.push_back(str);
		trie->insert(str.c_str());
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < w; i++) m[input[i]] = i;
	int b; cin >> b;
	while (b--) {
		ans = 0;
		memset(chk, 0, sizeof(chk));
		memset(schk, 0, sizeof(schk));
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> arr[i][j];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				string s;
				chk[i][j] = 1;
				Boggle(i, j, s+arr[i][j]);
				chk[i][j] = 0;
			}
		int cnt = 0;
		int Max = 0;
		string longest;
		for (int i = 0; i < w; i++) {
			if (schk[i]) {
				cnt++;
				if (Max < input[i].size()) {
					Max = input[i].size();
					longest = input[i];
				}
			}
		}
		cout << ans << ' ' << longest << ' ' << cnt << '\n';
	}
	delete trie;
	return 0;
}