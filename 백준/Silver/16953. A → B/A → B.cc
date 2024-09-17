#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	int ans = 1;
	bool flag = true;
	while (b != a) {
		if (b % 2 == 0 && b / 2) b /= 2;
		else if (b % 10 == 1) b /= 10;
		else {
			flag = false;
			break;
		}
		ans++;
	}
	
	cout << (flag ? ans : -1) << '\n';
	return 0;
}