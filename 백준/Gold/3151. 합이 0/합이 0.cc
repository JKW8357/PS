#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	long long cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			auto left = lower_bound(vec.begin() + j + 1, vec.end(), -(vec[i] + vec[j])) - vec.begin();
			auto right = upper_bound(vec.begin() + j + 1, vec.end(), -(vec[i] + vec[j])) - vec.begin();
			cnt += right - left;
		}
	}

	cout << cnt << '\n';
	return 0;
}