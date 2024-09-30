#include <bits/stdc++.h>
using namespace std;

int arr[100005];
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	arr[0] = 0;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr, arr + n + 1);
	
	for (int i = 1; i <= n; i++)
		pq.push(arr[i] - arr[i - 1]);

	long long ans = 0;
	while (k--) pq.pop();
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans << '\n';
	return 0;
}