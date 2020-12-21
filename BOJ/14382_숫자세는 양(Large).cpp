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
string quack;
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int arr[11] = { 0, };
		int n, s=0,end=0;
		cin >> n;
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n",i);
			continue;
		}
		while (end==0) {
			s++;
			int com = n * s;
			while (com != 0) {
				arr[com % 10]++;
				com /= 10;
			}
			for (int i = 0; i <= 9; i++) {
				if (arr[i] == 0) break;
				if (i == 9) end = 1;
			}
		}
		printf("Case #%d: %d\n", i, n*s);
	}
	return 0;
}



