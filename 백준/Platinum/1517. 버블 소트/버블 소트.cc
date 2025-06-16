#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

class SegmentTree {
private:
	vector<ll> node;
	int n;

	void init(int cur, int st, int en, vector<ll>& input) {
		if (st == en) {
			node[cur] = input[st];
			return;
		}
		int mid = (st + en) / 2;
		init(2 * cur, st, mid, input);
		init(2 * cur + 1, mid + 1, en, input);
		node[cur] = node[2 * cur] + node[2 * cur + 1];
	}

	void update(int cur, int st, int en, int idx, ll val) {
		if (st == en) {
			node[cur] = 1;
			return;
		}
		int mid = (st + en) / 2;
		if (idx <= mid) update(2 * cur, st, mid, idx, val);
		else update(2 * cur + 1, mid + 1, en, idx, val);
		node[cur] = node[2 * cur] + node[2 * cur + 1];
	}

	ll query(int cur, int st, int en, int l, int r) {
		if (l > en || r < st) return 0;
		if (l <= st && en <= r) return node[cur];
		int mid = (st + en) / 2;
		return query(2 * cur, st, mid, l, r) + query(2 * cur + 1, mid + 1, en, l, r);
	}

public:
	SegmentTree(int size) : n(size) { node.assign(4 * n, 0); }
	void init(vector<ll>& input) { init(1, 1, n, input); }
	void update(int idx, ll val) { update(1, 1, n, idx, val); }
	ll query(int l, int r) { return query(1, 1, n, l, r); }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	SegmentTree ST(n);
	vector<pll> arr(n + 1, { 0, 0 });
	for (int idx = 1; idx <= n; idx++) {
		ll val; cin >> val;
		arr[idx] = { val, idx };
	}

	sort(arr.begin(), arr.end());

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int idx = arr[i].second;
		ans += ST.query(idx + 1, n);
		ST.update(idx, 1);
	}

	cout << ans << '\n';
	return 0;
}