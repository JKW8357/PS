#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		priority_queue<ll, vector<ll>, greater<>> pq;
		int k;
		cin >> k;

		while (k--) {
			int num;
			cin >> num;
			pq.push(num);
		}

		ll ans = 0;
		while (pq.size() > 1) {
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();
			ans += a + b;
			pq.push(a + b);
		}

		cout << ans << '\n';
	}

	return 0;
}