#include <bits/stdc++.h>
using namespace std;

map<string, double> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string woods;
	double cnt = 0;
	while (getline(cin, woods)) {
		m[woods]++;
		cnt++;
	}

	vector<pair<string, double>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end());

	cout << fixed;
	cout.precision(4);
	for (auto i : vec) cout << i.first << ' ' << i.second * 100 / cnt << '\n';

	return 0;
}