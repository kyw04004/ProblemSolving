#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
pair<int,int> arr[46];
int main() {
	arr[0] = { 1,0 };
	arr[1] = { 0,1 };
	for (int i = 2; i <= 45; i++) {
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}
	int n;
	cin >> n;
	cout << arr[n].first << " " << arr[n].second;
	return 0;
}