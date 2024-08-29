#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<double> v;
	for (int i = 0; i < n; i++) {
		double num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < 7; i++) cout << v[i] << '\n';
	return 0;
}