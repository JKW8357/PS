#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		for (int i = 0; i < 3; i++) cin >> arr[i];
		ll d; cin >> d;
		sort(arr, arr + 3);
		ll tmp = (arr[0] + arr[1] + arr[2]) - d;

		arr[0] = min(arr[0], tmp / 3);
		arr[1] = min(arr[1], (tmp - arr[0]) / 2);
		arr[2] = tmp - (arr[0] + arr[1]);
		
		cout << arr[0] * arr[1] * arr[2] << '\n';
	}

	return 0;
}