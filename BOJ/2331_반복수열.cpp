#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int A, P, chk[240000], cnt;
int main(void) {
	cin >> A >> P;
	while (chk[A] == 0) {
		int sum = 0;
		cnt++;
		chk[A] = cnt;
		while (A > 0) {
			sum += pow(A % 10, P);
			A /= 10;
		}
		A = sum;
	}
	cout << chk[A] - 1;
	return 0;
}