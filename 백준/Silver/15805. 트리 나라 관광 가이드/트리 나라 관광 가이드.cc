#include <bits/stdc++.h>
using namespace std;

int arr[200005];
int parent[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	fill(parent, parent + n + 1, -1);
	
	int cnt = 1, root = arr[0];
	for (int i = 1; i < n; i++) {
		if (parent[arr[i]] != -1 || arr[i] == root) continue;
		parent[arr[i]] = arr[i - 1];
		++cnt;
	}

	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) cout << parent[i] << ' ';
	return 0;
}