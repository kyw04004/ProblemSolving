#include<stdio.h>
int XOR(int n)
{
	if (n % 4 == 0) return n;
	if (n % 4 == 1) return 1;
	if (n % 4 == 2) return n+1;
	if (n % 4 == 3) return 0;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b); 
		printf("%d\n",XOR(a-1)^XOR(b));
	}
	return 0;
}