#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
double M[3];
int main()
{
	double a, b, c;
	double d, e, f;
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	M[0] = a / d;
	M[1] = b / e;
	M[2] = c / f;
	sort(M, M + 3);
	printf("%f %f %f",a-d*M[0], b - e * M[0], c - f * M[0]);
	return 0;
}