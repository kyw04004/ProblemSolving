#include<stdio.h>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef pair<int, int> P;
int n,cnt;
char Map[101][101];
vector<P> alpha;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> Map[i][j];
			if (Map[i][j] != '.') alpha.push_back({i,j});
		}
	for (int i = 0; i < alpha.size()-2; i++) 
		for (int j = i + 1; j < alpha.size() - 1; j++) 
			for (int k = j + 1; k < alpha.size(); k++) {
				double a = double(alpha[j].first - alpha[i].first) / double(alpha[j].second - alpha[i].second);
				double b = double(alpha[k].first - alpha[i].first) / double(alpha[k].second - alpha[i].second);
				if (a == b) cnt++;
			}
	cout << cnt;
	return 0;
}