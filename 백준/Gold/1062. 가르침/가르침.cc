#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans = 0;
vector<string> words;

void solve(int state, int idx, int depth) {
	if (depth == k - 5) {
		int cnt = 0;
		for (const string& word : words) {
			bool check = true;
			for (char ch : word) {
				if (!(state & (1 << (ch - 'a')))) {
					check = false;
					break;
				}
			}
			if (check) cnt++;
		}
		ans = max(ans, cnt);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (state & (1 << i)) continue;
		solve(state | (1 << i), i + 1, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		words.push_back(word.substr(4, word.size() - 8));
	}

	if (k < 5) {
		cout << 0 << '\n';
		return 0;
	}

	int state = 0;
	vector<char> preset = { 'a', 'c', 'i', 'n', 't' };
	for (char c : preset) state |= (1 << (c - 'a'));

	solve(state, 0, 0);

	cout << ans << '\n';
	return 0;
}