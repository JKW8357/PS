#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
	int i = 1, sum = 0, idx = 1;
	while (idx <= n) {
		int cnt = min(n - idx + 1, i);
		sum += cnt * i;
		idx += cnt;
		i++;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	cout << sum(b) - sum(a - 1) << '\n';
	return 0;
}