#include <bits/stdc++.h>
using namespace std;

deque<int> cards;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		cards.push_back(num);
	}
	sort(cards.begin(), cards.end(), greater<int>());

	int score = 0;
	while (!cards.empty() && m > 0) {
		if (cards.front() >= 0) {
			score += cards.front();
			cards.pop_front();
		}

		if (!cards.empty()) cards.pop_back();
		else break;
		m--;
	}

	cout << score << '\n';
	return 0;
}