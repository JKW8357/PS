#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e9 + 7;

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
		node[cur] = (node[2 * cur] * node[2 * cur + 1]) % MOD;
	}

	void update(int cur, int st, int en, int idx, ll val) {
		if (st == en) {
			node[cur] = val;
			return;
		}
		int mid = (st + en) / 2;
		if (idx <= mid) update(2 * cur, st, mid, idx, val);
		else update(2 * cur + 1, mid + 1, en, idx, val);
		node[cur] = (node[2 * cur] * node[2 * cur + 1]) % MOD;
	}

	ll query(int cur, int st, int en, int l, int r) {
		if (l > en || r < st) return 1;
		if (l <= st && en <= r) return node[cur];
		int mid = (st + en) / 2;
		return (query(2 * cur, st, mid, l, r) * query(2 * cur + 1, mid + 1, en, l, r)) % MOD;
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

	int n, m, k;
	cin >> n >> m >> k;

	SegmentTree ST(n);
	vector<ll> arr(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	ST.init(arr);

	int q = m + k;
	while (q--) {
		int query; cin >> query;
		if (query == 1) {
			int idx; ll val;
			cin >> idx >> val;
			ST.update(idx, val);
		}
		else {
			int st, en;
			cin >> st >> en;
			cout << ST.query(st, en) << '\n';
		}
	}

	return 0;
}