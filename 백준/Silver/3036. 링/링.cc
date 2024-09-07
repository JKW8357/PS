#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ring;
	cin >> n >> ring;
	for (int i = 0; i < n - 1; i++) {
		int other;
		cin >> other;
		int GCD = gcd(ring, other);
		cout << ring / GCD << '/' << other / GCD << '\n';
	}
	
	return 0;
}