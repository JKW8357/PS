#include <bits/stdc++.h>
using namespace std;

int arr[12][12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	int ans = INT_MIN;
	vector<bool> mask(n, false);
	fill(mask.end() - k, mask.end(), true);

	do {
		vector<int> ingredients;
		for (int i = 0; i < mask.size(); i++)
			if (mask[i]) ingredients.push_back(i + 1);

		int taste = 0;
		for (int i = 0; i < ingredients.size() - 1; i++)
			for (int j = i + 1; j < ingredients.size(); j++)
				taste += arr[ingredients[i]][ingredients[j]];

		ans = max(ans, taste);
	} while (next_permutation(mask.begin(), mask.end()));

	cout << ans << '\n';
	return 0;
}