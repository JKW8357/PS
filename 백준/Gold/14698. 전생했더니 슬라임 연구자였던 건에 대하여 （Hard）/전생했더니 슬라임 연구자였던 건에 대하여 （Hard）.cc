#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod int(1e9 + 7)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		int n; cin >> n;

		for (int i = 0; i < n; i++) {
			ll num; cin >> num;
			pq.push(num);
		}

		ll energy = 1;
		while (pq.size() > 1) {
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();
			pq.push(a * b);
			energy *= ((a % mod) * (b % mod)) % mod;
			energy %= mod;
		}
		
		cout << energy << '\n';
	}

	return 0;
}