#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
#include<unordered_map>
using namespace std;
typedef long long ll;
int N, T;
typedef struct {
	int id;
	string com;
	int num;
} calc;
map<int, int> publicCard;
map<int, pair<int,int>> acquireGet;//id,n ¿˙¿Â
queue<calc> q;
vector<int> seq;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> T;
	for (int i = 0; i < T; i++) {
		int num; cin >> num;
		seq.push_back(num);
	}
	for (int i = 0; i < T; i++) {
		int id, num;
		string com;
		cin >> id >> com;
		if (com == "next") {
			q.push({ id, com, 0 });
		}
		else {
			cin >> num;
			q.push({ id, com, num });
		}
	}
	for (int i = 0; i < T; i++) {
		int now = seq[i];
		if (acquireGet[now].first) {
			if (publicCard[acquireGet[now].second] == 0) {
				publicCard[acquireGet[now].second] = 1;
				cout << acquireGet[now].first << '\n';
				acquireGet[now].first = acquireGet[now].second = 0;
			}
			else cout << acquireGet[now].first << '\n';
		}
		else {
			calc c = q.front();
			int id = c.id;
			string com = c.com;
			int num = c.num;
			q.pop();
			if (com == "acquire") {
				if (publicCard[num] == 0) publicCard[num] = 1;
				else {
					acquireGet[now].first = id;
					acquireGet[now].second = num;
				}
			}
			if (com == "release") publicCard[num] = 0;
			cout << id << '\n';
		}
	}
	return 0;
}