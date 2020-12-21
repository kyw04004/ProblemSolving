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
int t, a, b, c, AB,BC,AC,Max, sum;
int main() {
	cin >> t;
	while (t--) {
		Max = 0;
		cin >> a >> b >> c;
		cin >> AB >> BC >> AC;
		for (int i = 0; i <= min(a, b); i++) {
			sum = 0;
			sum += AB * i;
			for (int j = 0; j <= min(b-i, c); j++) {
				sum += BC * j;
				Max = max(Max, sum + AC*min(a-i,c-j));
				sum -= BC * j;
			}
			sum -= AB * i;
		}
		cout << Max << "\n";
	}
	return 0;
}