#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		ll dist1 = (x - x1) * (x - x1) + (y - y1) * (y - y1);
		ll dist2 = (x - x2) * (x - x2) + (y - y2) * (y - y2);
		dist.push_back({ dist1, dist2 });
	}

	sort(dist.begin(), dist.end());

	ll ans = dist.back().first;
	ll tmp = 0;
	for (auto& d : dist) tmp = max(tmp, d.second);
	ans = min(ans, tmp);

	for (int i = 0; i < n; i++) {
		ll tmp = 0;
		for (int j = i + 1; j < n; j++)
			tmp = max(tmp, dist[j].second);
		ll res = dist[i].first + tmp;
		ans = min(ans, res);
	}

	cout << ans << '\n';
	return 0;
}