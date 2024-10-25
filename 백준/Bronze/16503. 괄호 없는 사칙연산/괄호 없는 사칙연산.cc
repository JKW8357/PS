#include <bits/stdc++.h>
using namespace std;

int op(int n1, char o, int n2) {
	int res;
	if (o == '+') res = n1 + n2;
	else if (o == '-') res = n1 - n2;
	else if (o == '*') res = n1 * n2;
	else res = n1 / n2;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	char op1, op2;
	cin >> a >> op1 >> b >> op2 >> c;

	int res1 = op(op(a, op1, b), op2, c);
	int res2 = op(a, op1, op(b, op2, c));
	cout << min(res1, res2) << '\n' << max(res1, res2) << '\n';

	return 0;
}