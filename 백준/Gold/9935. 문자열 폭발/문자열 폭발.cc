#include <bits/stdc++.h>
using namespace std;

stack <char> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str, bomb;
	cin >> str >> bomb;

	string tmp;
	for (char c : str) {
		st.push(c);

		if (c == bomb.back()) {
			for (int i = bomb.size() - 1; i >= 0; i--) {
				if (!st.empty() && st.top() == bomb[i]) {
					tmp += st.top();
					st.pop();
				}

				else {
					reverse(tmp.begin(), tmp.end());
					for (char a : tmp) st.push(a);
					break;
				}
			}
			tmp.clear();
		}
	}

	if (st.empty()) cout << "FRULA\n";
	else {
		string ans;
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}

	return 0;
}