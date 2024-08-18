#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<long long, long long>> vec;

	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		vec.push_back({ a, b });
	}

	sort(vec.begin(), vec.begin() + n);

	long long sum = 0;
	for (int i = n - 1; i >= 0; i--)
		sum += vec[i].first * (i + 1) + vec[i].second;
	cout << sum;

	return 0;
}