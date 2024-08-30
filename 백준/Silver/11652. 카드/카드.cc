#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
	if (p1.second != p2.second) return p1.second > p2.second;
	return p1.first < p2.first;
}

unordered_map<ll, ll> um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		ll num;
		cin >> num;
		um[num]++;
	}

	vector<pair<ll, ll>> vec(um.begin(), um.end());
	sort(vec.begin(), vec.end(), cmp);
	cout << vec[0].first << '\n';
	return 0;
}