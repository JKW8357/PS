#include <bits/stdc++.h>
using namespace std;

bool function1(string pwd, string vowels) {
	for (int i = 0; i < vowels.size(); i++)
		if (pwd.find(vowels[i]) != string::npos) return true;
	return false;
}

bool function2(string pwd, string vowels) {
	int v = 0, c = 0;
	for (int i = 0; i < pwd.size(); i++) {
		if (vowels.find(pwd[i]) != string::npos) { c = 0; v++; }
		else { v = 0; c++; }
		if (v == 3 || c == 3) return false;
	}
	return true;
}

bool function3(string pwd) {
	for (int i = 0; i < pwd.size() - 1; i++)
		if (pwd[i] == pwd[i + 1] && pwd[i] != 'e' && pwd[i] != 'o') return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string vowels = "aeiou";

	string pwd;
	while (true) {
		cin >> pwd;
		if (pwd == "end") break;

		bool check1 = function1(pwd, vowels);
		bool check2 = function2(pwd, vowels);
		bool check3 = function3(pwd);

		if (check1 && check2 && check3) cout << "<" << pwd << "> is acceptable.\n";
		else cout << "<" << pwd << "> is not acceptable.\n";
	}

	return 0;
}
