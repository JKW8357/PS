#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int nge[1000005];
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = n; i >= 1; i--) {
		while (!st.empty() && st.top() <= arr[i]) st.pop();
		nge[i] = (!st.empty() ? st.top() : -1);
		st.push(arr[i]);
	}

	for (int i = 1; i <= n; i++) cout << nge[i] << ' ';
	return 0;
}