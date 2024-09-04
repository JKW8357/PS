#include <bits/stdc++.h>
using namespace std;

int sum[26][200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	for (int i = 1; i <= str.size(); i++) {
		for (int j = 0; j < 26; j++) sum[j][i] = sum[j][i - 1];
		sum[str[i - 1] - 'a'][i]++;
	}

	int tc;
	cin >> tc;

	while (tc--) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		cout << sum[c - 'a'][r + 1] - sum[c - 'a'][l] << '\n';
	}

	return 0;
}