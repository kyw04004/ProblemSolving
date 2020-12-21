#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
struct score {
	//char name[11];
	string name;
	int k;
	int e;
	int m;
};
int n;
bool compare(score a, score b)
{
	if (a.k != b.k) return a.k > b.k;
	else if (a.e != b.e) return a.e < b.e;
	else if (a.m != b.m) return a.m > b.m;
	else if(a.name != b.name) return a.name < b.name;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	score* s=new score[100001];
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].name;
		//scanf("%s", s[i].name);
		cin>> s[i].k >> s[i].e >> s[i].m;
	}
	sort(s + 1, s + n+1, compare);
	for (int i = 1; i <= n; i++)
	{
		//cout << s[i].name<<endl;
		printf("%s\n", s[i].name.c_str());
	}
	delete[] s;
	return 0;
}