#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <stack>
using namespace std;
typedef long long ll;
int distance(int E) {
	int Efloor = 0;
	int a = 1, sum = 0;
	while (E > sum) {
		sum += a;
		a += 2;
		Efloor++;
	}
	int R = 2 * (Efloor - 1);
	if (Efloor % 2 == 0) R -= E % 2;
	else if(E % 2 == 0) R -= 1;
	return R;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int A, B;
	cin >> A >> B;
	if (A > B) swap(A, B);
	int Afloor = 0, Bfloor = 0;

	//A, B 층수 구하기
	int a = 1,sum=0;
	while (A > sum) {
		sum += a;
		a += 2;
		Afloor++;
	}
	a = 1, sum = 0;
	while (B > sum) {
		sum += a;
		a += 2;
		Bfloor++;
	}

	//B 층수의 A의 삼각형 left, right 계산
	int left = A, right = A, floor = Afloor;
	while (floor < Bfloor) {
		floor++;
		left += 2 * (floor - 2) + 1;
		right += 2 * (floor - 1) + 1;
	}
	int ans = 0;

	//거리계산
	if (left <= B && B <= right) ans = distance(B) - distance(A);
	else {
		if (B < left) ans = distance(left) - distance(A) + abs(left - B);
		else ans = distance(right) - distance(A) + abs(right - B);
	}

	cout << ans;
	return 0;
}