#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	while (1) {
		string str;
		int ok = 1;
		int aeiou = 0;
		int notaeiou = 0;
		int keepaeiou = 0;
		int keepnotaeiou = 0;
		char before=NULL;
		cin >> str;
		if (str == "end") break;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				aeiou++, keepaeiou++, keepnotaeiou = 0;
				if(keepaeiou==3) ok = 0, i = str.size();
				if (str[i] == before && before != 'e' && before != 'o') ok = 0, i = str.size();
				before = str[i];
			}
			else {
				notaeiou++, keepnotaeiou++, keepaeiou = 0;
				if (keepnotaeiou == 3) ok = 0, i = str.size();
				if (str[i] == before) ok = 0, i = str.size();
				before = str[i];
			}
		}
		if (aeiou == 0) ok = 0;
		if (ok == 1) cout << "<" << str << ">" << " is acceptable." <<"\n";
		else cout << "<" << str << ">" << " is not acceptable."<< "\n";
	}
	return 0;
}