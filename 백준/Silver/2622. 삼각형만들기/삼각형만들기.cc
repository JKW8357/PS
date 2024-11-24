#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int cnt = 0;
	
	for (int a = (n + 1) / 2 - 1; a >= 1; a--)
		for (int b = a; b >= (n - a + 1) / 2; b--)
			cnt++;

	cout << cnt << '\n';
	return 0;
}