#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> arr;
ll inversionCount = 0;

void merge(int l, int mid, int r) {
	vector<int> tmp;
	int i = l, j = mid + 1;

	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
		else {
			tmp.push_back(arr[j++]);
			inversionCount += (mid - i + 1);
		}
	}

	while (i <= mid) tmp.push_back(arr[i++]);
	while (j <= r) tmp.push_back(arr[j++]);

	for (int k = 0; k < (int)tmp.size(); k++) arr[l + k] = tmp[k];
}

void mergeSort(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	merge(l, mid, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	mergeSort(0, n - 1);
	cout << inversionCount << '\n';

	return 0;
}