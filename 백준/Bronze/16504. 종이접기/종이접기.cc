#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long sum = 0;
	for (int i = 1; i <= n * n; i++) {
		int num;
		cin >> num;
		sum += num;
	}

	cout << sum << '\n';
	return 0;
}