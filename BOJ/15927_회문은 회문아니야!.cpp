#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int len = str.size();
	int chk = 0;
	for (int i = 0; i < len / 2; i++) // 문자열이 팰린드롬인지 확인
		if (str[i] != str[len - i -1])
			chk = 1;
	if (chk == 1) // 문자열이 팰린드롬X
		printf("%d", len);
	else // 문자열이 팰린드롬
	{
		for (int i = 0; i < len - 1; i++)
			if (str[i] != str[i + 1])
				chk = 1;
		if (chk == 0) // 모든 문자가 같으면 항상 팰린드롬
			printf("-1");
		else // 보통 팰린드롬은 1문자만 빼면 팰린드롬X
			printf("%d", len - 1);
	}
	return 0;
}