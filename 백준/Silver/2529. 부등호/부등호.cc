#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> inequality;
vector<string> ans;

void solve(const string& number, int state, int level) {
	if (level == n + 1) {
		ans.push_back(number);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (state & (1 << i)) continue;
		if (number[level - 1] - '0' > i && inequality[level - 1] == '>')
			solve(number + to_string(i), state | (1 << i), level + 1);
		if (number[level - 1] - '0' < i && inequality[level - 1] == '<')
			solve(number + to_string(i), state | (1 << i), level + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char s; cin >> s;
		inequality.push_back(s);
	}

	for (int i = 0; i <= 9; i++)
		solve(to_string(i), (1 << i), 1);

	cout << ans.back() << '\n' << ans.front() << '\n';
	return 0;
}