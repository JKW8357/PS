#include <bits/stdc++.h>
using namespace std;

int w[10];
int k[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++) cin >> w[i];
	for (int i = 0; i < 10; i++) cin >> k[i];
	sort(w, w + 10, greater<int>());
	sort(k, k + 10, greater<int>());

	cout << w[0] + w[1] + w[2] << ' ' << k[0] + k[1] + k[2] << '\n';
	return 0;
}