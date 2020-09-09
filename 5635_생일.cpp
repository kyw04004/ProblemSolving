#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
struct Student {
	int yy;
	int mm;
	int dd;
	string name;
};
Student arr[101];
bool compare(Student a, Student b) {
	if (a.yy != b.yy) return a.yy > b.yy;
	else if (a.mm != b.mm) return a.mm > b.mm;
	else if (a.dd != b.dd) return a.dd > b.dd;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i].name >> arr[i].dd >> arr[i].mm >> arr[i].yy;
	sort(arr, arr + n, compare);
	cout << arr[0].name << "\n";
	cout << arr[n-1].name << "\n";
	return 0;
}



