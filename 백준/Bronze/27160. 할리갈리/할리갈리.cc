#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		string fruit;
		int cnt;
		cin >> fruit >> cnt;
		um[fruit] += cnt;
	}

	for (auto i : um) {
		if (i.second == 5) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}