#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count(ll num1, ll num2) {
	ll res = 0;
	while (num1 != 0) {
		res += num1 / num2;
		num1 /= num2;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;
	ll two = count(n, 2) - count(m, 2) - count(n - m, 2);
	ll five = count(n, 5) - count(m, 5) - count(n - m, 5);
	cout << min(two, five) << '\n';
	return 0;
}