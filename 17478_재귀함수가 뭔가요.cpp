#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
void go(int depth, int end, string str)
{
	if (depth == end)
	{
		cout << str + "\"재귀함수가 뭔가요?\"" << "\n";
		cout << str + "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << "\n";
		cout << str + "라고 답변하였지." << "\n";
		return;
	}
	cout <<str+"\"재귀함수가 뭔가요?\""<<"\n";
	cout << str + "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어."<< "\n";
	cout << str + "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지."<< "\n";
	cout << str + "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""<<"\n";
	go(depth+1,end,str+"____");
	cout << str + "라고 답변하였지."<<"\n";
}
int main() {
	int n;
	scanf("%d", &n);
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	printf("\"재귀함수가 뭔가요?\"\n");
	printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
	printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
	printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
	go(1,n,"____");
	printf("라고 답변하였지.\n");
	return 0;
}