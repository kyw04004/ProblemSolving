#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int N, com = 1;
void makeTable(int num, int size) { // 숫자랑 배열크기
	if (size == 1) {
		if (num == 1) cout << '#';
		else cout << '.';
		return;
	}
	int left, right;
	if (2 * num <= size) {
		makeTable(num, size / 2);
		makeTable(0, size / 2);
	}
	else {
		if (num > 4) {
			int temp = 1;
			while (temp <= num) temp *= 2;
			temp /= 4;
			left = temp, right = temp;

			if (num - 2 * temp > temp) {
				left += temp;
				right += (num - 2 * temp - temp);
			}
			else left += (num - left - right);
		}
		else {
			if (num == 0) left = 0, right = 0;
			if (num == 1) left = 1, right = 0;
			if (num == 2) left = 1, right = 1;
			if (num == 3) left = 2, right = 1;
			if (num == 4) left = 2, right = 2;
		}
		makeTable(left, size / 2);
		makeTable(right, size / 2);
	}
}
int main() {
	cin >> N;
	while (N > com)
		com *= 2;
	makeTable(N, com);
	return 0;
}