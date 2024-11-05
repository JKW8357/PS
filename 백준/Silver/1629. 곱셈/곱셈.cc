#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll a, ll b, ll c) {
	if (b == 1) return a % c;

	ll tmp = power(a, b / 2, c);
	tmp = tmp * tmp % c;
	if (b % 2 == 0) return tmp % c;
	else return tmp * a % c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll a, b, c;
	cin >> a >> b >> c;
	cout << power(a, b, c) << '\n';

	return 0;
}