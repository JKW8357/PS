#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) arr[i] = i + 1;
	do {
		for (int i = 0; i < n; i++) cout << arr[i] << ' ';
		cout << '\n';
	} while (next_permutation(arr, arr + n));

	return 0;
}