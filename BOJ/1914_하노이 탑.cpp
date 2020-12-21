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
int n;
queue <P> q;
vector<int> v;
void honoi(int h, int a, int b, int c)
{
	if (h == 1) q.push({ a,c });
	else
	{
		honoi(h - 1, a, c, b);
		q.push({ a,c });
		honoi(h - 1, b, a, c);
	}
}
int main() {
	v.push_back(1);
	scanf("%d", &n);
	if(n<=20) honoi(n, 1, 2, 3);
	v[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < v.size(); k++) {
			int chk;
			v[k] *= 2;
			if (chk == 1) {
				chk = 0;
				v[k] += v[k-1]/10;
				v[k - 1] %= 10;
			}
			if (v[k] >= 10) {
				if (k == v.size() - 1) v.push_back(0);
				chk = 1;
			}
		}
	}
	int index = 0;
	while (v[index] == 0) {
		v[index] = 9;
		index++;
	}
	v[index]--;
	for (int k = v.size() - 1; k >= 0; k--) {
		if (v[v.size() - 1] == 0) continue;
		printf("%d", v[k]);
	}
	printf("\n");
	while (!q.empty())
	{
		printf("%d %d\n", q.front().first, q.front().second);
		q.pop();
	}
	return 0;
}