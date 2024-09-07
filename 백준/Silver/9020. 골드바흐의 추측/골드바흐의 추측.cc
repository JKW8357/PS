#include <bits/stdc++.h>
using namespace std;

vector<bool> state(10005, true);

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

	sieve(10000);

	int tc;
	cin >> tc;
	
	while (tc--) {
		int n;
		cin >> n;

		for (int i = n / 2; i >= 0; i--) {
			if (state[i] && state[n - i]) {
				cout << i << " " << n - i << '\n';
				break;
			}
		}
	}

	return 0;
}