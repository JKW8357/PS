#include <bits/stdc++.h>
using namespace std;

int arr[200005];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 1;
		for (int j = 0; j <= 3; j++) tmp *= arr[(i + j) % n];
		sum += tmp;
		v.push_back(tmp);
	}

	int size = v.size();
	while (q--) {
		int num;
		cin >> num;
		for (int i = 0; i <= 3; i++) {
			int idx = (num - i - 1 + size) % size;
			v[idx] *= -1;
			sum += 2 * v[idx];
		}
		cout << sum << '\n';
	}

	return 0;
}