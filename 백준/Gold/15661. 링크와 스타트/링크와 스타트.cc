#include <bits/stdc++.h>
using namespace std;

int arr[22][22];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int ans = INT_MAX;
	for (int bitmask = 1; bitmask < (1 << n) - 1; bitmask++) {
		vector<int> teamA, teamB;

		for (int i = 0; i < n; i++) {
			if (bitmask & (1 << i)) teamA.push_back(i);
			else teamB.push_back(i);
		}

		int diff = 0;
		int sizeA = (int)teamA.size();
		int sizeB = (int)teamB.size();

		for (int i = 0; i < sizeA - 1; i++)
			for (int j = i + 1; j < sizeA; j++)
				diff += (arr[teamA[i]][teamA[j]] + arr[teamA[j]][teamA[i]]);

		for (int i = 0; i < sizeB - 1; i++)
			for (int j = i + 1; j < sizeB; j++)
				 diff -= (arr[teamB[i]][teamB[j]] + arr[teamB[j]][teamB[i]]);

		ans = min(ans, abs(diff));
	}

	cout << ans << '\n';
	return 0;
}