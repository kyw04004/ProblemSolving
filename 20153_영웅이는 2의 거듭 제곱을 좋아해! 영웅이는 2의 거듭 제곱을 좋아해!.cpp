#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		sum ^= a;
		v.push_back(a);
	}
	int Max = sum;
	for (int i = 0; i < v.size(); i++) {
		int com = sum ^ v[i];
		Max = max(Max, com);
	}
	printf("%d", Max);
	printf("%d\n", Max);
	return 0;
}