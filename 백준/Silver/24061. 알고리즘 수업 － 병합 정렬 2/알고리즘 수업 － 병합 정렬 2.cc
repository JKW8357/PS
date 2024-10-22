#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt = 0;
bool flag = false;
int arr[500005];
int tmp[500005];

void merge(int st, int en) {
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid + 1;

	int idx = st;
	while (lidx <= mid && ridx <= en) {
		if (arr[lidx] <= arr[ridx]) tmp[idx++] = arr[lidx++];
		else tmp[idx++] = arr[ridx++];
	}

	while (lidx <= mid) tmp[idx++] = arr[lidx++];
	while (ridx <= en) tmp[idx++] = arr[ridx++];

	for (int i = st; i <= en; i++) {
		arr[i] = tmp[i];
		if (++cnt == k) {
			for (int j = 0; j < n; j++) cout << arr[j] << ' ';
			cout << '\n';
			flag = true;
			return;
		}
	}
}

void merge_sort(int st, int en) {
	if (flag) return;
	if (st >= en) return;

	int mid = midpoint(st, en);
	merge_sort(st, mid);
	merge_sort(mid + 1, en);
	merge(st, en);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	merge_sort(0, n - 1);
	if (!flag) cout << -1 << '\n';

	return 0;
}