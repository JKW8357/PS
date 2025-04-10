#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll twobyone[2005];
ll twobytwo[2005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	for (int i = 0; i < a; i++) cin >> twobyone[i];
	for (int i = 0; i < b; i++) cin >> twobytwo[i];

	sort(twobyone, twobyone + a, greater<ll>());
	sort(twobytwo, twobytwo + b, greater<ll>());

	ll ans = 0;
	int idx1 = 0, idx2 = 0, cur = 0;
	if (n % 2) {
		ans += twobyone[idx1++];
		cur++;
	}
	
	while (cur < n) {
		if (idx1 >= a - 1) ans += twobytwo[idx2++];
		else if (idx2 >= b) {
			ans += twobyone[idx1] + twobyone[idx1 + 1];
			idx1 += 2;
		}
		else {
			ll b1 = twobyone[idx1] + twobyone[idx1 + 1];
			ll b2 = twobytwo[idx2];
			if (b1 >= b2) {
				ans += b1;
				idx1 += 2;
			}
			else {
				ans += b2;
				idx2++;
			}
		}
		cur += 2;
	}

	cout << ans << '\n';
	return 0;
}