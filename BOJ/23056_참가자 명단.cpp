#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int N, M, classP[11];
struct player {
	int classNum;
	int nameS;
	string name;
};
vector<player> B, R;
bool compare(player a, player b) {
	if (a.classNum != b.classNum) return a.classNum < b.classNum;
	else if (a.nameS != b.nameS) return a.nameS < b.nameS;
	else if (a.name != b.name) return a.name < b.name;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	while (1) {
		int c;
		string name;
		cin >> c >> name;
		if (c == 0 && name == "0") break;
		if (classP[c] >= M) continue;
		classP[c]++;
		if (c % 2 == 1) B.push_back({ c, (int)name.size(), name });
		else R.push_back({ c, (int)name.size(), name });
	}
	sort(B.begin(), B.end(), compare);
	sort(R.begin(), R.end(), compare);
	for (int i = 0; i < (int)B.size(); i++)
		cout << B[i].classNum << ' ' << B[i].name << '\n';
	for (int i = 0; i < (int)R.size(); i++)
		cout << R[i].classNum << ' ' << R[i].name << '\n';
	return 0;
}