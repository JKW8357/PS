#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int>& arr, int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	InsertionSort(arr, n);
	for (int e : arr) cout << e << '\n';
	
	return 0;
}