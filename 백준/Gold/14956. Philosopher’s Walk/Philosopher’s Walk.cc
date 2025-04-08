#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const pii findCoord(int n, int m) {
	if (n == 2) {
		if (m == 1) return { 1, 1 };
		else if (m == 2) return { 1, 2 };
		else if (m == 3) return { 2, 2 };
		else return { 2, 1 };
	}

	int half = n / 2;
	int sect = half * half;

	if (m <= sect) {
		auto& [x, y] = findCoord(half, m);
		return { y, x };
	}
	else if (m <= 2 * sect) {
		auto& [x, y] = findCoord(half, m - sect);
		return { x, y + half };
	}
	else if (m <= 3 * sect) {
		auto& [x, y] = findCoord(half, m - 2 * sect);
		return { x + half, y + half };
	}
	else {
		auto& [x, y] = findCoord(half, m - 3 * sect);
		return { 2 * half - y + 1, half - x + 1 };
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	auto& [x, y] = findCoord(n, m);
	cout << x << ' ' << y << '\n';

	return 0;
}