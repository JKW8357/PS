#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.size(); i++)
		if (a[i] == '6') a[i] = '5';
	for (int i = 0; i < b.size(); i++)
		if (b[i] == '6') b[i] = '5';
	int min = stoi(a) + stoi(b);

	for (int i = 0; i < a.size(); i++)
		if (a[i] == '5') a[i] = '6';
	for (int i = 0; i < b.size(); i++)
		if (b[i] == '5') b[i] = '6';
	int max = stoi(a) + stoi(b);

	cout << min << ' ' << max;
	return 0;
}