#include <bits/stdc++.h>
using namespace std;

int n, k;
bool check(int num) {
	int max_val = 1;
	for (int i = 2; i <= num; i++) {
		while (num % i == 0) {
			max_val = i;
			num /= i;
		}
	}
	return max_val <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (check(i)) cnt++;
	cout << cnt << '\n';

	return 0;
}