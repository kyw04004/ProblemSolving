#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n, l, m, Max = 0;;
	vector < pair<int, int>> fish;
	cin >> n >> l >> m;
	for (int i = 1; i <= m; i++) {
		int garo, sero;
		cin >> garo >> sero;
		fish.push_back({ garo,sero });
	}
	sort(fish.begin(), fish.end());
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			int x = fish[i].first; // 가로
			int y = fish[j].second; // 세로
			for (int a = 1; (2*a+2) <= l; a++) {
				for (int b = (l - 2 * a) / 2; b >= 1; b--) {
					int cnt = 0;
					for (int c = 0; c < m; c++)
						if (x <= fish[c].first && fish[c].first <= x+a
							&&  y-b<= fish[c].second && fish[c].second <= y)
							cnt++;
					Max = max(Max, cnt);
				}
			}
		}
	}
	cout << Max << "\n";
	return 0;
}