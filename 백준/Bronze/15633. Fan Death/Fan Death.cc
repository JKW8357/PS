#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int sum = 0;
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0) sum += (i * i == n ? i : i + n / i);

	cout << sum * 5 - 24 << '\n';
	return 0;
}