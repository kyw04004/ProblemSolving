#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
int main() {
	int n, ans = 0;
	string s;
	cin >> n;
	int i = 666;
	while (1)
	{
		s = to_string(i);
		int ok = 0;
		for (int i = 0; i < s.size()-2; i++)
			if (s[i] == '6'&&s[i + 1] == '6'&&s[i + 2] == '6')
			{
				ok = 1;
				i = s.size();
			}
		if (ok==1)
			ans++;
		if (ans == n)
			break;
		i++;
	}
	cout << s;
	return 0;
}


