#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, n;
	cin >> a >> b >> c >> n;

	int maxScore = 0;
	while (3 * n--) {
		int teamScore = 0;
		for (int i = 0; i < 3; i++) {
			int sa, sb, sc;
			cin >> sa >> sb >> sc;
			teamScore += a * sa + b * sb + c * sc;
		}
		maxScore = max(maxScore, teamScore);
	}

	cout << maxScore << '\n';
	return 0;
}