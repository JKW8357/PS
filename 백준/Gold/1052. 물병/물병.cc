#include <bits/stdc++.h>
using namespace std;

int popCount(int num) {
	int count = 0;
	while (num) {
		num &= (num - 1);
		count++;
	}
	return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int ans = n;
	while (popCount(ans) > k) ans++;
	cout << ans - n << '\n';

    return 0;
}