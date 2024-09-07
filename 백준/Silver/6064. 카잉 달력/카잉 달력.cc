#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n, int x, int y) {
	int LCM = lcm(m, n);
	for (int i = x; i <= LCM; i += m)
		if (i % n == (n == y ? 0 : y)) return i; // n == y일 때의 예외 처리
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		cout << solve(m, n, x, y) << '\n';
	}
}

/*
연립 합동 방정식:
i ≡ x (mod m)
i ≡ y (mod n)
x부터 시작해 m씩 더해가며 i가 y를 만족하는지 확인
*/
