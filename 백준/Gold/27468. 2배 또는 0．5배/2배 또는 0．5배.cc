#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	cout << "YES\n";
	int num = 1;

	if (n % 4 != 2) {
		for (int i = 1; i <= n; i++) {
			cout << num << ' ';
			if (i % 2 == 1) num += 2;
			else if (i % 4 == 0) num += 1;
			else num -= 1;
		}
	}
	
	else {
		for (int i = 1; i <= n; i++) {
			cout << num << ' ';
			if (i % 2 == 0) num += 2;
			else if (i % 4 == 1) num += 1;
			else num -= 1;
		}
	}

	return 0;
}