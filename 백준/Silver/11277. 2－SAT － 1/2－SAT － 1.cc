#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> clauses;

bool check(int x, int y, int state) {
	bool a = (x > 0 ? (state & (1 << (x - 1))) != 0 : (state & (1 << (-x - 1))) == 0);
	bool b = (y > 0 ? (state & (1 << (y - 1))) != 0 : (state & (1 << (-y - 1))) == 0);
	return a || b;
}

bool solve(int state) {
	for (auto& clause : clauses)
		if (!check(clause.first, clause.second, state))
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	clauses.resize(m);
	for (int i = 0; i < m; i++)
		cin >> clauses[i].first >> clauses[i].second;

	bool canSolve = false;
	for (int bitmask = 0; bitmask < (1 << n); bitmask++)
		if (solve(bitmask)) canSolve = true;
	cout << (canSolve ? 1 : 0) << '\n';

	return 0;
}