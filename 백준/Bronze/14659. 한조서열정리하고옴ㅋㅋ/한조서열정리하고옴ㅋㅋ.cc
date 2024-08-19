#include <bits/stdc++.h>
using namespace std;

int arr[30005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int cur = 0, killed = 0;
	vector<int> vec;
	for (int i = 1; i < n; i++) {
		if (arr[cur] > arr[i]) {
			killed++;
			if (i == n - 1) vec.push_back(killed);
		}
		else {
			cur = i;
			vec.push_back(killed);
			killed = 0;
		}
	}

	cout << *max_element(vec.begin(), vec.end()) << '\n';
	return 0;
}