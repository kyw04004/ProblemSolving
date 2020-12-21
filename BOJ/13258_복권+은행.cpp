#include<stdio.h>
int main() {
	double n, sum, wow, week,kangho;
	scanf("%lf", &n);
	for (int i = 1; i <= n; i++)
	{
		double a;
		scanf("%lf", &a);
		sum += a;
		if (i == 1) kangho = a;
	}
	scanf("%lf %lf", &wow, &week);
	printf("%0.10lf",kangho + (kangho*wow*week) / sum);
	return 0;
}