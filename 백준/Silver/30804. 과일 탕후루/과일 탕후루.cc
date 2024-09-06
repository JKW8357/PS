#include <bits/stdc++.h>
using namespace std;

int fruits[200005];
unordered_map<int, int> types;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> fruits[i];

	int st = 1, en = 1, ans = 0;

	while (en <= n) {
		types[fruits[en]]++;
		if (types.size() > 2) {
			while (true)
				if (--types[fruits[st++]] == 0) break;
			types.erase(fruits[st - 1]);
		}
		ans = max(ans, en++ - st + 1);
	}

	cout << ans << '\n';
	return 0;
}