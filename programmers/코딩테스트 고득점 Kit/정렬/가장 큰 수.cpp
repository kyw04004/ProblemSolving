#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include<iostream>
using namespace std;
bool compare(string a, string b) {
	string ab = "", ba = "";
	ab += a, ab += b;
	ba += b, ba += a;
	return stoi(ab) > stoi(ba);
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str;
	for (int i = 0; i < numbers.size(); i++)
		str.push_back(to_string(numbers[i]));
	sort(str.begin(), str.end(), compare);
	for (int i = 0; i < str.size(); i++) {
		if (answer == "" && str[i] == "0") continue;
		answer += str[i];
	}
	if (answer == "") answer = "0";
	return answer;
}