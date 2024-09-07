#include <bits/stdc++.h>
using namespace std;

vector<bool> state(300000, true);

void sieve(int n) {
	state[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= n; j += i)
			state[j] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sieve(300000);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) return 0;

		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++)
			if (state[i]) cnt++;
		cout << cnt << '\n';
	}
}