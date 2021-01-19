#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
string str;
int Max = 0;
vector <int> getPi(string pattern) {
	int m = pattern.size();
	int j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}
	return pi;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str;
    for(int s=0;s < str.size()-1;s++) {
        string str2 = str.substr(s);
	    vector<int> pi = getPi(str2);
	    for (int i = 0; i < pi.size(); i++)
		    Max = max(Max, pi[i]);
    }
	cout << Max;
	return 0;
}
