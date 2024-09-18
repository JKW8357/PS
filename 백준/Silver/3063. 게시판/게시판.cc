#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		int poster = (x2 - x1) * (y2 - y1);
		int overlapped = 0;

		//AABB 충돌 판정 테크닉
		if (max(x1, x3) < min(x2, x4) && max(y1, y3) < min(y2, y4))
			overlapped = (max(x1, x3) - min(x2, x4)) * (max(y1, y3) - min(y2, y4));
		cout << poster - overlapped << '\n';
	}

	return 0;
}