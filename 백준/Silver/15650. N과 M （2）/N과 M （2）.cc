#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;
bool visited[10];

void solve(int num, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) cout << vec[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = num; i <= n; i++) {
		if (!visited[i]) {
			vec.push_back(i);
			visited[i] = true;
			solve(i + 1, depth + 1);
			vec.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	solve(1, 0);

	return 0;
}