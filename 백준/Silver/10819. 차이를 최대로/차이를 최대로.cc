#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) sum += abs(vec[i] - vec[i + 1]);
		ans = max(ans, sum);
	} while (next_permutation(vec.begin(), vec.end()));

	cout << ans << '\n';
	return 0;
}