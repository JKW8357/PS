#include <bits/stdc++.h>
using namespace std;

int arr[1005];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			v.push_back(arr[i] + arr[j]);
	sort(v.begin(), v.end());

	int ans = INT_MIN;
	for (int k = 0; k < n; k++)
		for (int l = k; l < n; l++)
			if (binary_search(v.begin(), v.end(), arr[l] - arr[k]) && arr[l] > ans) ans = arr[l];

	cout << ans << '\n';
	return 0;
}