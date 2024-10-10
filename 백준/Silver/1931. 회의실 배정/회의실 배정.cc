#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;
		v.push_back({ en, st });
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	int endtime = 0;
	for (auto lecture : v) {
		if (endtime <= lecture.second) {
			endtime = lecture.first;
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}