#include <bits/stdc++.h>
using namespace std;

string seats[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;

	int ans = 0;
	for (int i = 0; i < n; i++) cin >> seats[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - k + 1; j++) {
			bool flag = true;
			for (int p = j; p < j + k; p++)
				if (seats[i][p] == '1') flag = false;
			if (flag) ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}