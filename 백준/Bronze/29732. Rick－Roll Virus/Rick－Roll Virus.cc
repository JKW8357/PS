#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	string s;
	cin >> n >> m >> k >> s;

	int size = s.size();
	int mx = INT_MIN, mn = 0, cnt = 0;

	for (int i = 0; i < size; i++) {
		if (s[i] == 'R') {
			mn = max({ 0, i - k, mx + 1 });
			if (mn > mx) {
				mx = min(size - 1, i + k);
				cnt += mx - mn + 1;
			}
		}
	}

	cout << (cnt <= m ? "Yes\n" : "No\n");
	return 0;
}