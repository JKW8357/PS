#include <bits/stdc++.h>
using namespace std;

int n, m;
int idx[10];
bool isused[10];
int num[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << num[idx[i]] << ' ';
		cout << '\n';
		return;
	}

	int start = 0;
	if (k != 0) start = idx[k - 1] + 1;
	for (int i = start; i < n; i++) {
		idx[k] = i;
		func(k + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	func(0);

	return 0;
}