#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str, number;
	char cal;
	long long num1, num2;
	bool foundFirstNum = false;
	bool firstNumNegative = false;
	bool secondNumNegative = false;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (!foundFirstNum) {
			if (i == 0 && str[i] == '-') {
				firstNumNegative = true;
				continue;
			}

			if (isdigit(str[i])) number += str[i];
			else {
				num1 = stoll(number, nullptr, 8);
				if (firstNumNegative) num1 = -num1;
				number.clear();
				foundFirstNum = true;

				cal = str[i];
				if (str[i + 1] == '-') {
					secondNumNegative = true;
					i++;
					continue;
				}
			}
		}

		else number += str[i];
	}

	num2 = stoll(number, nullptr, 8);
	if (secondNumNegative) num2 = -num2;

	long long ans;
	if (cal == '+') ans = num1 + num2;
	else if (cal == '-') ans = num1 - num2;
	else if (cal == '*') ans = num1 * num2;
	else if (cal == '/') {
		if (num2 == 0) {
			cout << "invalid\n";
			return 0;
		}
		else ans = floor(double(num1) / num2);
	}

	if (ans >= 0) cout << oct << ans << '\n';
	else cout << '-' << oct << -ans << '\n';
	return 0;
}