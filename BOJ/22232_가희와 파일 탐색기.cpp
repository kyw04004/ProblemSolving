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
typedef unsigned long long ll;
int N, M;
unordered_map<string, int> priority;
typedef struct {
	string name;
	string extension;
}file;
bool compare(file a, file b) {
	if (a.name != b.name) return a.name < b.name;
	else if(priority[a.extension] != priority[b.extension])
		return priority[a.extension] > priority[b.extension];
	else return a.extension < b.extension;
}
vector<file> v;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string com = "";
		string name, exteinsion;
		string str; cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '.') {
				name = com;
				com = "";
			}
			else com += str[j];
		}
		exteinsion = com;
		v.push_back({ name, exteinsion });
	}
	for (int i = 1; i <= M; i++) {
		string str; cin >> str;
		priority[str] = 1;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++)
		cout << v[i].name << '.' << v[i].extension << '\n';
	return 0;
}