#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, r;
	cin >> a >> b >> r;

	int t = 0;
	arr[a][b] = 1;
	do {
		if (a + b + 2 < r) { a++; b++; }
		else { a /= 2; b /= 2; }
		arr[a][b]++; t++;
	} while (arr[a][b] != 2);
	
	cout << t << '\n';
	return 0;
}