#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int score = 0;
	int a; cin >> a;
	for (int i = 0; i < n - 1; i++) {
		int b; cin >> b;
		score += a * b;
		a += b;
	}
	
	cout << score << '\n';
	return 0;
}