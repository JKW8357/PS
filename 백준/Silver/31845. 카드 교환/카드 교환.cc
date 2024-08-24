#include <bits/stdc++.h>
using namespace std;

deque<int> cards;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cards.push_back(num);
	}
	sort(cards.begin(), cards.end(), greater<int>());

	int score = 0, cnt = 0;
	while (++cnt <= m && !cards.empty() && *cards.begin() > 0) {
		score += *cards.begin();
		cards.pop_front();
		if (!cards.empty()) cards.pop_back();
		else break;
	}

	cout << score << '\n';
	return 0;
}