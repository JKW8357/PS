#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, n;
	cin >> a >> b >> n;

	int x = a * n + b;
	for (int i = 0; i < n; i++) {
		cout << x << ' ';
		x += b;
	}
	
	return 0;
}