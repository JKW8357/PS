#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string p;
	cin >> p;
	int findx = p.find('x');

	if (findx != string::npos) {
		if (p[0] == '-' && p[1] == 'x') cout << -1 << '\n';
		else if (p[0] == 'x') cout << 1 << '\n';
		else if (p[0] != 'x') cout << p.substr(0, findx) << '\n';
	}
	else cout << 0 << '\n';

	return 0;
}