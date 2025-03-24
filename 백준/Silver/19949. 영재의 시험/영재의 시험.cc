#include <bits/stdc++.h>
using namespace std;

int res = 0;
int answer[10];

void solve(int questionNum, int score, int prev, int prevPrev) {
	if (questionNum == 10) {
		if (score >= 5) res++;
		return;
	}

	for (int i = 1; i <= 5; i++) {
		if (i == prev && prev == prevPrev) continue;
		if (answer[questionNum] == i) solve(questionNum + 1, score + 1, i, prev);
		else solve(questionNum + 1, score, i, prev);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 10; i++) cin >> answer[i];
	solve(0, 0, -1, -1);
	cout << res << '\n';

	return 0;
}