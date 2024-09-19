#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str, cipher;
	getline(cin, str);
	cin >> cipher;
	int size1 = str.size();
	int size2 = cipher.size();

	for (int i = 0; i < size1; i++)
		if (str[i] != ' ') str[i] = (str[i] - cipher[i % size2] + 25) % 26 + 'a';

	cout << str << '\n';
	return 0;
}