#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string num;
	cin >> num;

	int size = num.size();
	sort(num.begin(), num.begin() + size, greater<int>());

	int tmp = 0;
	for (int i = 0; i < size; i++) tmp += num[i] - '0';
	if (tmp % 3 == 0 && num[size - 1] == '0') cout << num << '\n';
	else cout << -1 << '\n';

	return 0;
}