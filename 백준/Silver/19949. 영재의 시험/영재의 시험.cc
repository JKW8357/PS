#include <bits/stdc++.h>
using namespace std;

int res = 0;
int answer[12];

void solve(int score, int num, int choosed1, int choosed2) {
	if (num == 10) {
		if (score >= 5) res++;
		return;
	}

	for (int i = 1; i <= 5; i++) {
		if (choosed1 == choosed2 && choosed2 == i) continue;
		if (answer[num] == i) solve(score + 1, num + 1, choosed2, i);
		else solve(score, num + 1, choosed2, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++) cin >> answer[i];
	solve(0, 0, 0, 0);
	cout << res << '\n';

	return 0;
}