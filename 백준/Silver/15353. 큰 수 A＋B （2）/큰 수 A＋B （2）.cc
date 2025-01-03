#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	
	int carry = 0;
	string output;

	int i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || carry) {
		int x = (i >= 0) ? (a[i--] - '0') : 0;
		int y = (j >= 0) ? (b[j--] - '0') : 0;
		int sum = x + y + carry;
		output += sum % 10 + '0';
		carry = sum / 10;
	}

	reverse(output.begin(), output.end());
	cout << output << '\n';

	return 0;
}