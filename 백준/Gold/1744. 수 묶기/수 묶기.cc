#include <bits/stdc++.h>
using namespace std;

priority_queue<int> PositivePq;
priority_queue<int, vector<int>, greater<>> NegativePq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int num;
		cin >> num;
		if (num > 0) PositivePq.push(num);
		else NegativePq.push(num);
	}
	
	int ans = 0;
	while (!PositivePq.empty()) {
		int num1 = PositivePq.top();
		PositivePq.pop();
		if (!PositivePq.empty()) {
			int num2 = PositivePq.top();
			PositivePq.pop();
			ans += max(num1 * num2, num1 + num2);
		}
		else ans += num1;
	}

	while (!NegativePq.empty()) {
		int num1 = NegativePq.top();
		NegativePq.pop();
		if (!NegativePq.empty()) {
			int num2 = NegativePq.top();
			NegativePq.pop();
			ans += num1 * num2;
		}
		else ans += num1;
	}

	cout << ans << '\n';
	return 0;
}