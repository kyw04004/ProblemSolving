#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
int n, ing[16][6];
int mp, mf, ms, mu, Min = 1e4, com;
vector<int> pr;
vector<pair<int,string>> ans;
void go(int depth, int p, int f, int s, int u, int sum,string str) {
	if (depth > n) {
		if (p >= mp && f >= mf && s >= ms && u >= mu && Min >= sum)
			Min = sum, ans.push_back({ sum,str });
		return;
	}
	char c = 'a' + depth;
	go(depth + 1, p + ing[depth][1], f + ing[depth][2]
		, s + ing[depth][3], u + ing[depth][4], sum + ing[depth][5], str + c );
	go(depth + 1, p, f, s, u, sum, str);
}
int main() {
	cin >> n;
	cin >> mp >> mf >> ms >> mu;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 5; j++)
			cin >> ing[i][j];
	go(1, 0, 0, 0, 0, 0,"");
	sort(ans.begin(), ans.end());
	if (Min == 1e4) printf("-1\n");
	else {
		printf("%d\n", Min);
		for (int i = 0; i < ans[0].second.size(); i++) {
			pr.push_back(ans[0].second[i]-'a');
		}
		sort(pr.begin(), pr.end());
		for (int i = 0; i < pr.size(); i++)
			printf("%d ", pr[i]);
	}
	return 0;
}