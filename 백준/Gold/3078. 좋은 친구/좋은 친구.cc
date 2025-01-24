#include <bits/stdc++.h>
using namespace std;

int length[300005];
int cnt[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string name; cin >> name;
		length[i] = (int)name.size();
	}

	long long ans = 0;
	for (int i = 1; i <= k + 1; i++) cnt[length[i]]++;
	for (int i = 1; i <= n; i++) {
		cnt[length[i]]--;
		ans += cnt[length[i]];
		if (i + k + 1 <= n) cnt[length[i + k + 1]]++;
	}

	cout << ans << '\n';
	return 0;
}