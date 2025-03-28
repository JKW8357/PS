#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) q.push(i);

	for (ll i = 1; i < n; i++) {
		ll cnt = (i * i * i - 1) % q.size();
		while (cnt--) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}
	
	cout << q.front() << '\n';
	return 0;
}