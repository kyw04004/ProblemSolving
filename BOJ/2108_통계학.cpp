#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
vector<int> v;
vector<int> Maxv[500005];
int arr[8005], Max = 1;
double sum;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int val; cin >> val;
		arr[val + 4000]++;
		v.push_back(val);
		sum += (double)val;
	}
	for (int i = 0; i <= 8000; i++) {
		if (arr[i] >= Max) {
			Max = arr[i]; //����
			Maxv[Max].push_back(i - 4000);//����
		}
	}
	sort(v.begin(), v.end());
	cout << fixed;
	cout.precision(0);
	if (sum < 0 && sum*10/2 >= -5) cout << 0 << '\n';
	else cout << sum / n << '\n';
	cout << v[n / 2] << '\n';
	if (Maxv[Max].size() >= 2) {
		sort(Maxv[Max].begin(), Maxv[Max].end());
		cout << Maxv[Max][1] << '\n';
	}
	else cout << Maxv[Max][0] << '\n';
	cout << v[v.size() - 1] - v[0] << '\n';
	return 0;
}