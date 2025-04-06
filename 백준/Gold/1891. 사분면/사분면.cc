#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll d, a, b;
string num;
ll nx, ny;

pll findCoord(ll x, ll y, int idx, ll n) {
	if (idx == d) return { x, y };

	ll half = n / 2;
	ll dx = (num[idx] == '1' || num[idx] == '4') ? half : 0;
	ll dy = (num[idx] == '1' || num[idx] == '2') ? half : 0;

	return findCoord(x + dx, y + dy, idx + 1, half);
}

string findNumber(ll cx, ll cy, ll n, const string& ans) {
	if (n == 1) return ans;

	ll half = n / 2;
	if (nx >= cx + half && ny >= cy + half)
		return findNumber(cx + half, cy + half, half, ans + '1');
	if (nx < cx + half && ny >= cy + half)
		return findNumber(cx, cy + half, half, ans + '2');
	if (nx < cx + half && ny < cy + half)
		return findNumber(cx, cy, half, ans + '3');
	if (nx >= cx + half && ny < cy + half)
		return findNumber(cx + half, cy, half, ans + '4');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> d >> num;
	cin >> a >> b;

	ll n = (ll)1 << d;
	pll coord = findCoord(0, 0, 0, n);
	nx = coord.first + a, ny = coord.second + b;

	if (nx < 0 || nx >= n || ny < 0 || ny >= n) cout << -1 << '\n';
	else {
		string ans = findNumber(0, 0, n, "");
		cout << ans << '\n';
	}

	return 0;
}