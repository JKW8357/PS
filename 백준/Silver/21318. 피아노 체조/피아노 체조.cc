#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int mistakes[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n - 1; i++)
		mistakes[i] = mistakes[i - 1] + (arr[i] > arr[i + 1] ? 1 : 0);
	mistakes[n] = mistakes[n - 1];

	int q;
	cin >> q;
	while (q--) {
		int st, en;
		cin >> st >> en;
		cout << mistakes[en - 1] - mistakes[st - 1] << '\n';
	}

	return 0;
}