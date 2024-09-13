#include <bits/stdc++.h>
using namespace std;

int rooms[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> rooms[i];

	int b, c;
	cin >> b >> c;
	for (int i = 0; i < n; i++) rooms[i] = (rooms[i] - b > 0 ? rooms[i] - b : 0);

	long long cnt = n;
	for (int i = 0; i < n; i++) cnt += (rooms[i] - 1 + c) / c;

	cout << cnt << '\n';
	return 0;
}