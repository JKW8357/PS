#include <bits/stdc++.h>
using namespace std;

int plan[1005];
int studied[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++) cin >> plan[i];
	for (int i = 0; i < n; i++) cin >> studied[i];
	for (int i = 0; i < n; i++)
		if (plan[i] <= studied[i]) ans++;

	cout << ans << '\n';
	return 0;
}