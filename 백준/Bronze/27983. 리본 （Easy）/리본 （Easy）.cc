#include <bits/stdc++.h>
using namespace std;

int X[1005];
int L[1005];
char C[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> X[i];
	for (int i = 1; i <= n; i++) cin >> L[i];
	for (int i = 1; i <= n; i++) cin >> C[i];

	int cnt = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (abs(X[i] - X[j]) <= (L[i] + L[j]) && C[i] != C[j]) {
				cout << "YES\n" << i << ' ' << j << '\n';
				return 0;
			}
		}
	}

	cout << "NO\n";
	return 0;
}