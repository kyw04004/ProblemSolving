#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
set<int> S;
set<int>::iterator iter;
map<int, int> M;
int N, X[1000005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		S.insert(X[i]);
	}
	int cnt = 0;
	for (iter = S.begin(); iter != S.end(); iter++) M[*iter] = cnt++;
	for (int i = 0; i < N; i++)
		cout << M[X[i]] << ' ';
	return 0;
}