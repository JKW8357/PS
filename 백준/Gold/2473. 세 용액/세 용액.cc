#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int s1, s2, s3;
	ll sum = 3 * ll(1e9) + 1;
	for (int i = 0; i < n - 2; i++) {
		int l = i + 1, r = n - 1;
		while (l < r) {
			ll diff = arr[i] + arr[l] + arr[r];
			if (sum > llabs(diff)) {
				sum = llabs(diff);
				s1 = arr[i];
				s2 = arr[l];
				s3 = arr[r];
			}
			else diff > 0 ? r-- : l++;
		}
	}

	cout << s1 << ' ' << s2 << ' ' << s3 << '\n';
	return 0;
}