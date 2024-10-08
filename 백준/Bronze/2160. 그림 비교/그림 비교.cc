#include <bits/stdc++.h>
using namespace std;

char pictures [55][5][7];

int compare(char v1[5][7], char v2[5][7]) {
	int cnt = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 7; j++)
			if (v1[i][j] != v2[i][j]) cnt++;
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int num = 1; num <= n; num++) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 7; j++)
				cin >> pictures[num][i][j];
	}

	int minDiff = INT_MAX;
	pair<int, int> ans = {};
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			int diff = compare(pictures[i], pictures[j]);
			if (minDiff > diff) {
				minDiff = diff;
				ans = { i, j };
			}
		}
	}

	cout << ans.first << ' ' << ans.second << '\n';
	return 0;
}