#include <bits/stdc++.h>
using namespace std;

vector<int> result;
vector<bool> used(5005);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}

	for (int st = (n + 1) / 2; st >= 1; st--) {
		for (int i = st; i <= n; i += n / 2) {
			if (!used[i]) {
				used[i] = true;
				result.push_back(i);
			}
		}
	}

	for (int x : result) cout << x << ' ';
	return 0;
}