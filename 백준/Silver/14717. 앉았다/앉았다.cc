#include <bits/stdc++.h>
using namespace std;

multiset<int> cards;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 10; i++) {
		cards.insert(i);
		cards.insert(i);
	}

	int a, b;
	cin >> a >> b;

	cards.erase(cards.find(a));
	cards.erase(cards.find(b));
	vector<int> others(cards.begin(), cards.end());

	int cnt = 0;
	for (int i = 0; i < 17; i++) {
		for (int j = i + 1; j < 18; j++) {
			int c = others[i];
			int d = others[j];

			if (a == b) {
				if (c == d && a > c) cnt++;
				else if (c != d) cnt++;
			}

			else if (c != d && (a + b) % 10 > (c + d) % 10) cnt++;
		}
	}

	cout << fixed;
	cout.precision(3);
	cout << double(cnt) / 153 << '\n';
	return 0;
}