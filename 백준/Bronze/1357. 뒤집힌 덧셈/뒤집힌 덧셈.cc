#include <bits/stdc++.h>
using namespace std;

int rev(int x) {
	string str = to_string(x);
	reverse(str.begin(), str.end());
	return stoi(str);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	cin >> x >> y;
	cout << rev(rev(x) + rev(y)) << '\n';

	return 0;
}