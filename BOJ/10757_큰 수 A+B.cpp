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
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str1, str2;
	stack<int> st;
	cin >> str1 >> str2;
	int index1 = str1.size() - 1;
	int index2 = str2.size() - 1;
	int up = 0;
	while (index1 >= 0 || index2 >= 0) {
		int sum = up;
		if (index1 >= 0) {
			int a = str1[index1] - '0';
			sum += a;
		}
		if (index2 >= 0) {
			int b = str2[index2] - '0';
			sum += b;
		}
		st.push(sum % 10);
		up = sum / 10;
		if (index1 >= 0) index1--;
		if (index2 >= 0) index2--;
	}
	if (up) st.push(1);
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}