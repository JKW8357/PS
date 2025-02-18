#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
vector<int> arr;
string result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		if (!dq.empty() && dq.front() < i - l + 1) dq.pop_front();
		while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();

		dq.push_back(i);
		result += to_string(arr[dq.front()]) + " ";
	}

	cout << result << '\n';
	return 0;
}