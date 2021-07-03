#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
int N,M;
vector<string> input;
vector<pair<pair<int, int>, string>> output;
map<string, int> m;
int main() 	{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		if (str.size() < M) continue;
		input.push_back(str);
		m[str]++;
	}
	for (int i = 0; i < input.size(); i++)
		output.push_back({ {100000 - m[input[i]], 10-input[i].size()},input[i] });
	sort(output.begin(), output.end());
	for (int i = 0; i < output.size(); i++) {
		if (i > 0 && output[i - 1] == output[i]) continue;
		cout << output[i].second << '\n';
	}
	return 0;
}