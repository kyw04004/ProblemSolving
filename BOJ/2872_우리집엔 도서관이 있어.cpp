#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
int n, arr[300005];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int com = n;
	for (int i = n; i >= 1; i--) 
		if (arr[i] == com) com--;
	printf("%d", com);
	return 0;
}