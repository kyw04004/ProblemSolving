#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
	int a1 = 0, a2 = 0, a3 = 0, Max = 0;
	int arr1[10] = { 1,2,3,4,5, };
	int arr2[10] = { 2,1,2,3,2,4,2,5, };
	int arr3[10] = { 3,3,1,1,2,2,4,4,5,5 };
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == arr1[i % 5]) a1++;
		if (answers[i] == arr2[i % 8]) a2++;
		if (answers[i] == arr3[i % 10]) a3++;
	}
	if (a1 > Max) Max = a1;
	if (a2 > Max) Max = a2;
	if (a3 > Max) Max = a3;
	vector<int> ret;
	if (a1 == Max) ret.push_back(1);
	if (a2 == Max) ret.push_back(2);
	if (a3 == Max) ret.push_back(3);
	return ret;
}