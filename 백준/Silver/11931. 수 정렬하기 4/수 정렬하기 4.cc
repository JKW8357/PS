#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 1000000;
bool arr[2000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		arr[x + OFFSET] = true;
	}

	for (int i = 2000000; i >= 0; i--)
		if (arr[i]) cout << i - OFFSET << '\n';

	return 0;
}
