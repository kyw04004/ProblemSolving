#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int n, arr[1000001],input[100001];
int go(int num) {
	int val = 0;
	for (int i = 1; i <= sqrt(num); i++) {
		if (num%i == 0) {
			if (num / i == i) val -= arr[i];
			val += arr[num / i];
			val += arr[i];
		}
	}
	return val;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a]++;
		input[i] = a;
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", go(input[i])-1);
	return 0;
}