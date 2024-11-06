#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> height;
vector<ll> width;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll w, h, k;
	cin >> w >> h >> k;

	int n; cin >> n;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		int cut; cin >> cut;
		height.push_back(cut - tmp);
		tmp = cut;
	}
	height.push_back(h - tmp);
	sort(height.begin(), height.end());

	int m; cin >> m;
	tmp = 0;
	for (int i = 0; i < m; i++) {
		int cut; cin >> cut;
		width.push_back(cut - tmp);
		tmp = cut;
	}
	width.push_back(w - tmp);
	sort(width.begin(), width.end());

	ll cnt = 0;
	int hPtr = n, wPtr = 0;
	while (hPtr >= 0) {
		while (wPtr <= m && height[hPtr] * width[wPtr] <= k) wPtr++;
		cnt += wPtr;
		hPtr--;
	}

	cout << cnt << '\n';
	return 0;
}