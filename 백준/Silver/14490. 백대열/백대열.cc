#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int n, m;
	scanf("%d:%d", &n, &m);

	int GCD = gcd(n, m);
	n /= GCD; m /= GCD;

	printf("%d:%d", n, m);

	return 0;
}