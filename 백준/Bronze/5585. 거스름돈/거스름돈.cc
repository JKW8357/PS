#include <bits/stdc++.h>
using namespace std;

int arr[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int change = 1000 - n;

	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (change == 0) break;
		cnt += change / arr[i];
		change %= arr[i];
	}
	
	cout << cnt << '\n';
	return 0;
}