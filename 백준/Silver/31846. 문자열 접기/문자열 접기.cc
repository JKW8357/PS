#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	string s;
	cin >> n >> s >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		string str = s.substr(l - 1, r - l + 1);
		vector<int> scores;

		for (int i = 0; i < str.size(); i++) {
			int left = i, right = i + 1, score = 0;
			while (left >= 0 && right < str.size())
				if (str[left--] == str[right++]) score++;
			scores.push_back(score);
		}

		cout << *max_element(scores.begin(), scores.end()) << '\n';
	}

	return 0;
}