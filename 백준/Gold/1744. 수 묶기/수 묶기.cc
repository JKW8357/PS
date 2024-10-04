#include <bits/stdc++.h>
using namespace std;

priority_queue<int> PositivePq;
priority_queue<int, vector<int>, greater<>> NegativePq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans = 0;
	while (n--) {
		int num;
		cin >> num;
		if (num > 0) PositivePq.push(num);
		else NegativePq.push(num);
	}
	
	while (!PositivePq.empty()) {
		int num1 = PositivePq.top();
		PositivePq.pop();
		int num2 = 1;
		if (!PositivePq.empty()) {
			num2 = PositivePq.top();
			PositivePq.pop();
			ans += max(num1 * num2, num1 + num2);
		}
		else ans += num1 * num2;
	}

	while (!NegativePq.empty()) {
		int num1 = NegativePq.top();
		NegativePq.pop();
		int num2 = 1;
		if (!NegativePq.empty()) {
			num2 = NegativePq.top();
			NegativePq.pop();
		}
		ans += num1 * num2;
	}

	cout << ans << '\n';

	return 0;
}