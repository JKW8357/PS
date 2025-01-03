#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	if (a.size() < b.size()) swap(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	int carry = 0;
	string output;

	for (int i = 0; i < (int)b.size(); i++) {
		int tmp = (a[i] - '0') + (b[i] - '0') + carry;
		output += tmp % 10 + '0';
		carry = tmp / 10;
	}

	for (int i = (int)b.size(); i < (int)a.size(); i++) {
		int tmp = (a[i] - '0') + carry;
		output += tmp % 10 + '0';
		carry = tmp / 10;
	}

	if (carry) output += carry + '0';

	reverse(output.begin(), output.end());
	cout << output << '\n';

	return 0;
}