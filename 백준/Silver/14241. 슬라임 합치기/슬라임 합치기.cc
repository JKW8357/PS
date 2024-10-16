#include <bits/stdc++.h>
using namespace std;

int arr[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int score = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			score += arr[i] * arr[j];
	
	cout << score << '\n';
	return 0;
}