#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	string animal;
	cin >> n >> animal >> k;

	if (animal == "annyong") cout << (k % 2 == 0 ? k - 1 : k) << '\n';
	else if (k % 2 != 0) cout << (n != k ? k + 1 : k - 1) << '\n';
	else cout << k << '\n';

	return 0;
}