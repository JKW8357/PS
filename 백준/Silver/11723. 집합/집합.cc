#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	int s = 0;
	while (tc--) {
		string cmd;
		int x;

		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			s |= (1 << (x - 1));
		}

		else if (cmd == "remove") {
			cin >> x;
			s &= ~(1 << (x - 1));
		}

		else if (cmd == "check") {
			cin >> x;
			cout << ((s >> (x - 1)) & 1) << '\n';
		}

		else if (cmd == "toggle") {
			cin >> x;
			s ^= (1 << (x - 1));
		}

		else if (cmd == "all") s = (s << 20) - 1;

		else s = 0;
	}

	return 0;
}