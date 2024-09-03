#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool visited[10];
vector<int> vec;

void solve(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) cout << vec[i] << ' ';
		cout << '\n';
		return;
	}

	int tmp = -1;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && arr[i] != tmp) {
			vec.push_back(arr[i]);
			visited[i] = true;
			tmp = vec[depth];
			solve(depth + 1);
			vec.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	solve(0);

	return 0;
}