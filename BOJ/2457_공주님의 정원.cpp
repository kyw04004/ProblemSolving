#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
priority_queue<P, vector<P>, greater<P>> pq;
priority_queue<int, vector<int>, less<int>> com;
int main()
{
	int n,cnt=0,right=-1,chk=1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		pq.push({ 100 * a + b, 100 * c + d });
	}
	while (!pq.empty())
	{
		if (pq.top().first <= 301)
		{
			cnt = 1;
			if (right < pq.top().second) right = pq.top().second;
			pq.pop();
		}
		else break;
	}
	while (right<=1130 && right!=-1 && !pq.empty())
	{
		if (pq.top().first <= right)
		{
			chk = 0;
			int element = pq.top().second;
			com.push(element);
			pq.pop();
		}
		else if(chk==0)
			chk = 1, right = com.top(), cnt++;
		else break;
	}
	if (chk == 0) right = com.top(), cnt++;
	if (right <= 1130) printf("0");
	else printf("%d", cnt);
	return 0;
}