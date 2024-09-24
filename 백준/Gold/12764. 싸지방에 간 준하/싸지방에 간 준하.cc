#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;

class cmp {
public:
	bool operator()(tup t1, tup t2) { return get<1>(t1) > get<1>(t2); }
};

int cnt[100005];
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> seats;
priority_queue<tup, vector<tup>, cmp> endTime;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p, q;
		cin >> p >> q;
		v.push_back({ p, q });
	}

	sort(v.begin(), v.end());

	int maxSeats = -1;
	int requiredSeats = 0;
	int seatNumber = 0;

	for (int i = 0; i < n; i++) {
		int p = v[i].first;
		int q = v[i].second;

		while (!endTime.empty() && get<1>(endTime.top()) <= p) {
			seats.push(get<2>(endTime.top()));
			endTime.pop();
		}

		if (!seats.empty()) {
			seatNumber = seats.top();
			seats.pop();
		}

		else seatNumber = ++requiredSeats;

		endTime.push({ p, q, seatNumber });
		cnt[seatNumber]++;
		maxSeats = max(maxSeats, seatNumber);
	}

	cout << maxSeats << '\n';
	for (int i = 1; i <= maxSeats; i++) cout << cnt[i] << ' ';
	return 0;
}
