#include <bits/stdc++.h>
using namespace std;

string str = "DCBAE";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int sum = a + b + c + d;
		cout << str[sum] << '\n';
	}

	return 0;
}