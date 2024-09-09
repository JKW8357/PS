#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str, target, nstr;
	cin >> str >> target;
	for (char c : str) if (!isdigit(c)) nstr += c;
	cout << (nstr.find(target) != string::npos ? 1 : 0) << '\n';

	return 0;
}