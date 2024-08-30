#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string vowels = "aeiou";
	string pwd;
	while (true) {
		cin >> pwd;
		if (pwd == "end") break;

		bool check1 = false;
		for (int i = 0; i < vowels.size(); i++)
			if (pwd.find(vowels[i]) != string::npos) { check1 = true; break; }

		bool check2 = true;
		int v = 0, c = 0;
		if (check1) {
			for (int i = 0; i < pwd.size(); i++) {
				if (vowels.find(pwd[i]) != string::npos) { c = 0; v++; }
				else { v = 0; c++; }
				if (v == 3 || c == 3) { check2 = false; break; }
			}
		}

		bool check3 = true;
		if (check1 && check2) {
			for (int i = 0; i < pwd.size() - 1; i++) {
				if (pwd[i] == pwd[i + 1]) {
					if (pwd[i] == 'e' || pwd[i] == 'o') continue;
					else { check3 = false; break; }
				}
			}
		}

		if (check1 && check2 && check3) cout << "<" << pwd << "> is acceptable.\n";
		else cout << "<" << pwd << "> is not acceptable.\n";
	}

	return 0;
}