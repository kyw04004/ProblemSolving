#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int n, m;
pair<int, int> arr[100001];
pair<string, int> name[100001];
string ans[100001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> name[i].first >> name[i].second;
	for (int i = 0; i < m; i++) {
		int val;
		cin >> val;
		arr[i] = {val,i};
	}
	sort(arr, arr + m);
	int index = 1;
	for (int i = 0; i < m; i++) {
		if (arr[i].first <= name[index].second)
			ans[arr[i].second] = name[index].first;
		else index++, i--;
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << "\n";
 	return 0;
}