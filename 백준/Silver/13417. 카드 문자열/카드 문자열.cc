#include <bits/stdc++.h>
using namespace std;

char arr[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		deque<char> ans;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (ans.empty() || c <= ans[0]) ans.push_front(c);
			else ans.push_back(c);
		}
		
		for (auto i : ans) cout << i;
		cout << '\n';
	}

	return 0;
}