#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int x, y, p1, p2,ans;
int main() {
	cin >> x >> y >> p1 >> p2;
	for (int i = 0;i<=100; i++)
		for (int j = 0;j<=100; j++) 
			if (x*i + p1 == y * j + p2) {
				cout << x * i + p1 << "\n";
				return 0;
			}
	cout << "-1" << "\n";
	return 0;
}