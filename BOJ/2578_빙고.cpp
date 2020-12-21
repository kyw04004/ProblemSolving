#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
P arr[6][6];
int cnt,chk,ans;
int main() {
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			scanf(" %d", &arr[i][j].first);
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
		{
			cnt++;
			int a,bingo=0;
			scanf(" %d", &a);
			for (int ii = 1; ii <= 5; ii++)
				for (int jj = 1; jj <= 5; jj++)
					if (arr[ii][jj].first == a)
						arr[ii][jj].second = 1,ii = 6, jj = 6;
			if (arr[1][1].second&&arr[1][2].second&&arr[1][3].second&&arr[1][4].second&&arr[1][5].second)
				bingo++;
			if (arr[2][1].second&&arr[2][2].second&&arr[2][3].second&&arr[2][4].second&&arr[2][5].second)
				bingo++;
			if (arr[3][1].second&&arr[3][2].second&&arr[3][3].second&&arr[3][4].second&&arr[3][5].second)
				bingo++;
			if (arr[4][1].second&&arr[4][2].second&&arr[4][3].second&&arr[4][4].second&&arr[4][5].second)
				bingo++;
			if (arr[5][1].second&&arr[5][2].second&&arr[5][3].second&&arr[5][4].second&&arr[5][5].second)
				bingo++;
			if (arr[1][1].second&&arr[2][1].second&&arr[3][1].second&&arr[4][1].second&&arr[5][1].second)
				bingo++;
			if (arr[1][2].second&&arr[2][2].second&&arr[3][2].second&&arr[4][2].second&&arr[5][2].second)
				bingo++;
			if (arr[1][3].second&&arr[2][3].second&&arr[3][3].second&&arr[4][3].second&&arr[5][3].second)
				bingo++;
			if (arr[1][4].second&&arr[2][4].second&&arr[3][4].second&&arr[4][4].second&&arr[5][4].second)
				bingo++;
			if (arr[1][5].second&&arr[2][5].second&&arr[3][5].second&&arr[4][5].second&&arr[5][5].second)
				bingo++;
			if (arr[1][1].second&&arr[2][2].second&&arr[3][3].second&&arr[4][4].second&&arr[5][5].second)
				bingo++;
			if (arr[1][5].second&&arr[2][4].second&&arr[3][3].second&&arr[4][2].second&&arr[5][1].second)
				bingo++;
			if (bingo >= 3&&chk==0)
				chk = 1,ans = cnt;
		}
	printf("%d", ans);
	return 0;
}