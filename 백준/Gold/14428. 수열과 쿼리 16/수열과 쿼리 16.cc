#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmentTree {
private:
	vector<ll> node;
	vector<ll> index;
	int n;

	int init(int cur, int st, int en) {
		if (st == en) return node[cur] = st;
		int mid = (st + en) / 2;
		int left = init(2 * cur, st, mid);
		int right = init(2 * cur + 1, mid + 1, en);
		return node[cur] = (index[left] <= index[right] ? left : right);
	}

	int update(int cur, int st, int en, int idx, ll val) {
		if (st == en) {
			index[idx] = val;
			return node[cur] = st;
		}
		int mid = (st + en) / 2;
		int left, right;
		if (idx <= mid) {
			left = update(cur * 2, st, mid, idx, val);
			right = node[cur * 2 + 1];
		}
		else {
			left = node[cur * 2];
			right = update(cur * 2 + 1, mid + 1, en, idx, val);
		}
		return node[cur] = (index[left] <= index[right] ? left : right);
	}

	int query(int cur, int st, int en, int l, int r) {
		if (l > en || r < st) return -1;
		if (l <= st && en <= r) return node[cur];
		int mid = (st + en) / 2;
		int left = query(2 * cur, st, mid, l, r);
		int right = query(2 * cur + 1, mid + 1, en, l, r);
		if (left == -1) return right;
		if (right == -1) return left;
		return index[left] <= index[right] ? left : right;
	}

public:
	SegmentTree(int size, vector<ll>& input) : n(size), index(input) {
		node.assign(4 * n, 0);
		init(1, 1, n);
	}

	void update(int idx, ll val) { update(1, 1, n, idx, val); }

	int query(int l, int r) { return query(1, 1, n, l, r); }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vector<ll> arr(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	SegmentTree ST(n, arr);

	int m; cin >> m;
	while (m--) {
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