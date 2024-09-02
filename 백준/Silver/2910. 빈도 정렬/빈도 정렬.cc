#include <bits/stdc++.h>
using namespace std;

int arr[1005];
unordered_map<int, int> freq;
unordered_map<int, int> first;

bool cmp(int p1, int p2) {
	if (freq[p1] != freq[p2]) return freq[p1] > freq[p2];
	return first[p1] < first[p2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		freq[arr[i]]++;
		if (!first[arr[i]]) first[arr[i]] = i;
	}

	stable_sort(arr + 1, arr + n + 1, cmp);
	for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
	return 0;
}