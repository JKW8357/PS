#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	
	ll oddSum = 0;
	ll evenSum = 0;
	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		if (i % 2 != 0) oddSum += num;
		else evenSum += num;
	}

	if (n == 3) ans = evenSum >= oddSum ? evenSum - oddSum : -1;
	else ans = llabs(evenSum - oddSum);
	cout << ans << '\n';
	return 0;
}