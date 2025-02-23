#include <bits/stdc++.h>
using namespace std;

deque<int> num;
vector<int> result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) num.push_back(i);

	for (int i = 0; i < n; i++) {
		if (k >= n - i - 1) {
			k -= (n - i - 1);
			result.push_back(num.back());
			num.pop_back();
		}
		else {
			result.push_back(num.front());
			num.pop_front();
		}
	}

	for (int x : result) cout << x << ' ';
	return 0;
}