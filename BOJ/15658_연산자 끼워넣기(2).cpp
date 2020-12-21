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
int n, arr[101];
int Plus, Minus, Mul, Div, Max = -1e9, Min = 1e9;
void go(int Depth,int sum, int Plus, int Minus, int Mul, int Div) {
	if (Depth == n) {
		Max = max(Max, sum);
		Min = min(Min, sum);
		return;
	}
	if (Plus >= 1) go(Depth + 1, sum + arr[Depth + 1], Plus - 1, Minus, Mul, Div);
	if (Minus >= 1) go(Depth + 1, sum - arr[Depth + 1], Plus, Minus-1, Mul, Div);
	if (Mul >= 1) go(Depth + 1, sum * arr[Depth + 1], Plus, Minus, Mul-1, Div);
	if (Div >= 1) go(Depth + 1, sum / arr[Depth + 1], Plus , Minus, Mul, Div-1);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> Plus >> Minus >> Mul >> Div;
	go(1,arr[1], Plus,Minus,Mul,Div);
	cout << Max << "\n";
	cout << Min << "\n";
	return 0;
}