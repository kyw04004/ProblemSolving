#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n;
pair<string, string> str[1001];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i].first;
		str[i].second = str[i].first;
	}
	for(int k=0;k<n;k++)
		for (int i = 0; i < str[i].first.size(); i++)
		{
			if (str[k].first[i] == 'k')
				str[k].first[i] = 'c';
			else if ('e' < str[k].first[i] && str[k].first[i] <= 'n')
			{
				if (str[k].first[i] == 'n'&&str[k].first[i + 1] == 'g')
				{
					for (int j = i + 1; j < str[k].first.size()-1; j++)
						str[k].first[j] = str[k].first[j + 1];
					str[k].first[str[k].first.size() - 1] = NULL;
				}
				else str[k].first[i]--;
			}
			else
				str[k].first[i] = str[k].first[i];
		}
	sort(str, str + n);
	for (int i = 0; i < n; i++)
		cout << str[i].second << '\n';
	return 0;
}