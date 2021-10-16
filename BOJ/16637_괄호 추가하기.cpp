#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int N, inteNum, Max = INT_LEAST32_MIN;
string str;
vector<int> num, comNum;
vector<char> ops, comOps;
void makeSeq(vector<int> v, int idx) {
	if (v.size()) {
		comNum = num;
		comOps = ops;
		for (int i = 0; i < v.size(); i++) {
			int one = comNum[v[i]];
			int two = comNum[v[i]+1];
			char op = comOps[v[i]];
			if (op == '+') one += two;
			else if (op == '-') one -= two;
			else one *= two;
			two = 0;
			op = '+';
			comNum[v[i]] = one;
			comNum[v[i]+1] = two;
			comOps[v[i]] = op;
		}
		int sum = comNum[0];
		for (int i = 0; i < comNum.size() - 1; i++) {
			char op = comOps[i];
			int two = comNum[i + 1];
			if (op == '+') sum += two;
			else if (op == '-') sum -= two;
			else  sum *= two;
		}
		Max = max(Max, sum);
	}
	for (int i = idx; i < inteNum - 1; i++) {
		v.push_back(i);
		makeSeq(v, i+2);
		v.pop_back();
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> str;
	inteNum = (N - 1) / 2 + 1;
	for (int i = 1; i <= inteNum; i++)
		num.push_back(str[(i - 1) * 2] - '0');
	for (int i = 1; i < inteNum; i++)
		ops.push_back(str[(i - 1) * 2 + 1]);
	if (N == 1) cout << str;
	else {
		vector<int> v;
		makeSeq(v, 0);
		cout << Max;
	}
	return 0;
}