#include <bits/stdc++.h>
using namespace std;

double number[26];
stack<double> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string postfix;
	cin >> n >> postfix;
	for (int i = 0; i < n; i++) cin >> number[i];

	for (char c : postfix) {
		if (isalpha(c)) st.push(number[c - 'A']);
		else {
			double num2 = st.top(); st.pop();
			double num1 = st.top(); st.pop();
			
			if (c == '+') st.push(num1 + num2);
			else if (c == '-') st.push(num1 - num2);
			else if (c == '*') st.push(num1 * num2);
			else st.push(num1 / num2);
		}
	}

	double result = st.top();
	cout << fixed; cout.precision(2);
	cout << result << '\n';

	return 0;
}