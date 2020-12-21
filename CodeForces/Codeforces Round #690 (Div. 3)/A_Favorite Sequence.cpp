#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		int arr[301];
		for (int i = 1; i <= n; i++) cin >> arr[i];
		int st = 1, en = n;
		while (en >= st) {
			if (st == en) printf("%d", arr[st]);
			else printf("%d %d ", arr[st], arr[en]);
			st++, en--;
		}
		printf("\n");
	}
	return 0;
}