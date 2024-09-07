#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	while(true) {
		if (isprime(n)) {
			string num = to_string(n);
			string rev_num = to_string(n);
			reverse(rev_num.begin(), rev_num.end());
			if (num == rev_num) {
				cout << num;
				return 0;
			}
		}
		n++;
	}
}