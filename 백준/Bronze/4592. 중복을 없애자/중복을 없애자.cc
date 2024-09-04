#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		int last = -1;

		while (n--) {
			int cur;
			cin >> cur;
			if (cur != last) {
				cout << cur << ' ';
				last = cur;
			}
		}

		cout << "$\n";
	}

	return 0;
}