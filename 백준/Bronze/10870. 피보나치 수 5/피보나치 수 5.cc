#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
	if (n <= 1) return n;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cout << fibonacci(n) << '\n';

	return 0;
}