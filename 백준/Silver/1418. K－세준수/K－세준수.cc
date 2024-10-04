#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<bool> state(100005, true);

void sieve() {
	state[1] = false;
	for (int i = 2; i <= 100000; i++) {
		if (!state[i]) continue;
		for (int j = i; j <= n; j += i)
			if (state[j]) state[j] = false;
	}
}

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

	sieve();
	cin >> n >> k;

	int cnt = 1;
	for (int i = 1; i <= n; i++)
		if (state[i] && check(i)) cnt++;
	cout << cnt << '\n';

	return 0;
}