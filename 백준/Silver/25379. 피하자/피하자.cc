#include <bits/stdc++.h>
using namespace std;

int arr[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	int c = arr[0] % 2;
	long long cnt1 = 0, cnt2 = 0, s1 = 0, s2 = 0;

	for (int i = 1; i < n; i++) {
		if (arr[i] % 2 == c) cnt1 += s1;
		else s1++;
	}

	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] % 2 == c) cnt2 += s2;
		else s2++;
	}

	cout << min(cnt1, cnt2);

	return 0;
}