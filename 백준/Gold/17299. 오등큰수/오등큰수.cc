#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int cnt[1000005];
int ngf[1000005];
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	for (int i = n; i >= 1; i--) {
		while (!st.empty() && cnt[st.top()] <= cnt[arr[i]]) st.pop();
		ngf[i] = (!st.empty() ? st.top() : -1);
		st.push(arr[i]);
	}

	for (int i = 1; i <= n; i++) cout << ngf[i] << ' ';
	return 0;
}