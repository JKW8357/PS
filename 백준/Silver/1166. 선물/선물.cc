#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, l, w, h;

bool param(double a) {
	return (ll)(l / a) * (ll)(w / a) * (ll)(h / a) >= n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> w >> h;

	// 매개변수가 정수가 아닌 경우에도 매개변수 탐색이 가능하다.
	// 다만 부동 소수점 오차를 고려해야 함에 주의한다.
	double lo = 0, hi = 1e9;
	for (int i = 0; i < 100; i++) {
		double mid = midpoint(lo, hi);
		if (param(mid)) lo = mid;
		else hi = mid;
	}

	cout << fixed;
	cout.precision(10);
	cout << lo << '\n';

	return 0;
}