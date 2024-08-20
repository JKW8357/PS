#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	cout << (str1.size() >= str2.size() ? "go" : "no") << '\n';
	return 0;
}