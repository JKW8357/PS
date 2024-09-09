#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	int size1 = a.size();
	int size2 = b.size();

	long long ans = 0;
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++)
			ans += (a[i] - '0') * (b[j] - '0');

	cout << ans << '\n';
	return 0;
}