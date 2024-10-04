#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<bool> state(100005, true);
vector<int> primes;

void sieve() {
	state[1] = false;
	for (int i = 2; i * i <= k; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= k; j += i)	state[j] = false;
	}
}

bool check(int num) {
	int maxPrime = 1;
	for (int prime : primes) {
		while (num % prime == 0) {
			maxPrime = prime;
			num /= prime;
		}
		if (num == 1) break;
	}
	if (num != 1) maxPrime = max(maxPrime, num);
	return maxPrime <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	sieve();
	for (int i = 2; i <= k; i++) if (state[i]) primes.push_back(i);

	int cnt = 1;
	for (int i = 2; i <= n; i++) if (check(i)) cnt++;
	cout << cnt << '\n';

	return 0;
}