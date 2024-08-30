#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int ngf[1000005];
int cnt[1000005];
pair<int, int> arr[1000005];
stack<pair<int, int>> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].X;
		cnt[arr[i].X]++;
	}

	for (int i = 1; i <= n; i++) {
		arr[i].Y = cnt[arr[i].X];
	}

	for (int i = n; i >= 1; i--) {
		while (!st.empty() && st.top().Y <= arr[i].Y) st.pop();
		ngf[i] = (!st.empty() ? st.top().X : -1);
		st.push(arr[i]);
	}

	for (int i = 1; i <= n; i++) cout << ngf[i] << ' ';
	return 0;
}