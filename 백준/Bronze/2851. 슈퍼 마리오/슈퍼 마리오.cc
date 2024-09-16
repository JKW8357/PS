#include <bits/stdc++.h>
using namespace std;

int mushrooms[11];
int sum[11];
int tmp[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 10; i++) {
		cin >> mushrooms[i];
		sum[i] += sum[i - 1] + mushrooms[i];
	}
	
	for (int i = 1; i <= 10; i++) tmp[i] = abs(100 - sum[i]);
	int min_val = *min_element(tmp + 1, tmp + 11);
	for (int i = 10; i >= 1; i--) {
		if (tmp[i] == min_val) {
			cout << sum[i] << '\n';
			break;
		}
	}

	return 0;
}