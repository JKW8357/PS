#include <bits/stdc++.h>
using namespace std;

int popCount(int num) {
	int res = 0;
	for (int i = 0; i < 32; i++) res += (num >> i) & 1;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cout << popCount(n ^ (~n + 1)) << '\n';

	return 0;
}