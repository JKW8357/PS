#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> order;
vector<int> multitap;

int getEraseIdx(int cur) {
	int eraseIdx = 0;
	int leastUsage = 0;

	for (int i = 0; i < multitap.size(); i++) {
		auto it = find(order.begin() + cur + 1, order.begin() + k, multitap[i]);
		if (it == order.end()) return i;

		int idx = it - order.begin();
		if (leastUsage < idx) {
			leastUsage = idx;
			eraseIdx = i;
		}
	}

	return eraseIdx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	order.resize(k);
	for (int i = 0; i < k; i++) cin >> order[i];

	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (find(multitap.begin(), multitap.end(), order[i]) != multitap.end()) continue;

		else if (multitap.size() >= n) {
			int eraseIdx = getEraseIdx(i);
			multitap.erase(multitap.begin() + eraseIdx);
			cnt++;
		}

		multitap.push_back(order[i]);
	}

	cout << cnt << '\n';
	return 0;
}
