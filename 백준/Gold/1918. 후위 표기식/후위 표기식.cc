#include <bits/stdc++.h>
using namespace std;

stack<char> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	string ans;
	for (char c : str) {
		if (isalpha(c)) ans += c;

		else if (c == '(') st.push(c);

		else if (c == ')') {
			while (st.top() != '(') {
				ans += st.top();
				st.pop();
			}
			st.pop();
		}

		else if (c == '*' || c == '/') {
			while (!st.empty() && st.top() != '(' && !(st.top() == '+' || st.top() == '-')) {
				ans += st.top();
				st.pop();
			}
			st.push(c);
		}

		else {
			while (!st.empty() && st.top() != '(') {
				ans += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	cout << ans << '\n';
	return 0;
}