#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 1000000;
int arr[2000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		arr[x + OFFSET]++;
	}

	for (int i = 0; i <= 2000000; i++)
		while (arr[i]--) cout << i - OFFSET << '\n';

	return 0;
}