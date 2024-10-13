#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> lines;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		lines.push_back({ a, b });
	}

	sort(lines.begin(), lines.end());

	int total = 0;
	int st, en;
	tie(st, en) = lines[0];

	for (auto curLine : lines) {
		if (curLine.first <= en) en = max(en, curLine.second);
		else {
			total += en - st;
			tie(st, en) = curLine;
		}
	}

	total += en - st;
	cout << total << '\n';
	return 0;
}
